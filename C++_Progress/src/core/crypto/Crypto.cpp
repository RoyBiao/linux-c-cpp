/*
 * Crypto.cpp
 *
 *  Created on: 2015-12-29
 *      Author: ruibiao
 */

#include "Crypto.h"

Crypto::Crypto() {
}

Crypto::~Crypto() {
}

void Crypto::des() {
	//主要是打印一些基本信息，方便调试：
	cout << "DES Parameters: " << endl;
	cout << "Algorithm name : " << DES::StaticAlgorithmName() << endl;

	unsigned char key[DES::DEFAULT_KEYLENGTH];
	unsigned char input[DES::BLOCKSIZE] = "12345";
	unsigned char output[DES::BLOCKSIZE];
	unsigned char txt[DES::BLOCKSIZE];

	cout << "input is: " << input << endl;

	//可以理解成首先构造一个加密器
	DESEncryption encryption_DES;

	//回忆一下之前的背景，对称加密算法需要一个密匙。加密和解密都会用到。
	//因此，设置密匙。
	encryption_DES.SetKey(key, DES::KEYLENGTH);
	//进行加密
	encryption_DES.ProcessBlock(input, output);

	//显示结果
	//for和for之后的cout可有可无，主要为了运行的时候看加密结果
	//把字符串的长度写成一个常量其实并不被推荐。
	//不过笔者事先知道字符串长，为了方便调试，就直接写下。
	//这里主要是把output也就是加密后的内容，以十六进制的整数形式输出。
	for (int i = 0; i < 5; i++) {
		cout << hex << (int) output[i] << ends;
	}
	cout << endl;

	//构造一个加密器
	DESDecryption decryption_DES;

	//由于对称加密算法的加密和解密都是同一个密匙，
	//因此解密的时候设置的密匙也是刚才在加密时设置好的key
	decryption_DES.SetKey(key, DES::KEYLENGTH);
	//进行解密，把结果写到txt中
	//decryption_DES.ProcessAndXorBlock( output, xorBlock, txt );
	decryption_DES.ProcessBlock(output, txt);

	//以上，加密，解密还原过程已经结束了。以下是为了验证：
	//加密前的明文和解密后的译文是否相等。
	if (memcmp(input, txt, 5) != 0) {
		cerr << "DES Encryption/decryption failed.\n";
		abort();
	}
	cout << "DES Encryption/decryption succeeded.\n";
}

void Crypto::aes() {

	//AES中使用的固定参数是以类AES中定义的enum数据类型出现的，而不是成员函数或变量
	//因此需要用::符号来索引
	cout << "AES Parameters: " << endl;
	cout << "Algorithm name : " << AES::StaticAlgorithmName() << endl;

	//Crypto++库中一般用字节数来表示长度，而不是常用的字节数
	cout << "Block size     : " << AES::BLOCKSIZE * 8 << endl;
	cout << "Min key length : " << AES::MIN_KEYLENGTH * 8 << endl;
	cout << "Max key length : " << AES::MAX_KEYLENGTH * 8 << endl;

	//AES中只包含一些固定的数据，而加密解密的功能由AESEncryption和AESDecryption来完成
	//加密过程
	AESEncryption aesEncryptor; //加密器

	unsigned char aesKey[AES::DEFAULT_KEYLENGTH]; //密钥
	unsigned char inBlock[AES::BLOCKSIZE] = "123456789"; //要加密的数据块
	unsigned char outBlock[AES::BLOCKSIZE]; //加密后的密文块
	unsigned char xorBlock[AES::BLOCKSIZE]; //必须设定为全零

	memset(xorBlock, 0, AES::BLOCKSIZE); //置零

	aesEncryptor.SetKey(aesKey, AES::DEFAULT_KEYLENGTH); //设定加密密钥
	aesEncryptor.ProcessAndXorBlock(inBlock, xorBlock, outBlock); //加密

	//以16进制显示加密后的数据
	for (int i = 0; i < 16; i++) {
		cout << hex << (int) outBlock[i] << " ";
	}
	cout << endl;

	//解密
	AESDecryption aesDecryptor;
	unsigned char plainText[AES::BLOCKSIZE];

	aesDecryptor.SetKey(aesKey, AES::DEFAULT_KEYLENGTH);
	//细心的朋友注意到这里的函数不是之前在DES中出现过的：ProcessBlock，
	//而是多了一个Xor。其实，ProcessAndXorBlock也有DES版本。用法跟AES版本差不多。
	//笔者分别在两份代码中列出这两个函数，有兴趣的朋友可以自己研究一下有何差异。
	aesDecryptor.ProcessAndXorBlock(outBlock, xorBlock, plainText);

	for (int i = 0; i < 16; i++) {
		cout << plainText[i];
	}
	cout << endl;
}

//void Crypto::rsa() {
//	void GenerateRSAKey(unsigned int keyLength, const char *privFilename,
//			const char *pubFilename, const char *seed);
//	string RSAEncryptString(const char *pubFilename, const char *seed,
//			const char *message);
//	string RSADecryptString(const char *privFilename, const char *ciphertext);
//	RandomPool & GlobalRNG();
//
//	char priKey[128] = { 0 };
//	char pubKey[128] = { 0 };
//	char seed[1024] = { 0 };
//	// 生成 RSA 密钥对
//	strcpy(priKey, "pri"); // 生成的私钥文件
//	strcpy(pubKey, "pub"); // 生成的公钥文件
//	strcpy(seed, "seed");
//	GenerateRSAKey(1024, priKey, pubKey, seed);
//
//	// RSA 加解密
//	char message[1024] = { 0 };
//	cout << "Origin Text:\t" << "Hello World!" << endl << endl;
//	strcpy(message, "Hello World!");
//	string encryptedText = RSAEncryptString(pubKey, seed, message); // RSA 公匙加密
//	cout << "Encrypted Text:\t" << encryptedText << endl << endl;
//	string decryptedText = RSADecryptString(priKey, encryptedText.c_str()); // RSA 私匙解密
//	cout << "EecryptedText Text:\t" << encryptedText << endl << endl;
//}
//
//void Crypto::sha() {
//
//}
//
////------------------------
//// 生成RSA密钥对
////------------------------
//void GenerateRSAKey(unsigned int keyLength, const char *privFilename,
//		const char *pubFilename, const char *seed) {
//	RandomPool randPool;
//	randPool.Put((byte *) seed, strlen(seed));
//
//	RSAES_OAEP_SHA_Decryptor priv(randPool, keyLength);
//	HexEncoder privFile(new FileSink(privFilename));
//
//	priv.DEREncode(privFile);
//	privFile.MessageEnd();
//
//	RSAES_OAEP_SHA_Encryptor pub(priv);
//	HexEncoder pubFile(new FileSink(pubFilename));
//	pub.DEREncode(pubFile);
//	pubFile.MessageEnd();
//}
//
////------------------------
//// RSA加密
////------------------------
//string RSAEncryptString(const char *pubFilename, const char *seed,
//		const char *message) {
//	FileSource pubFile(pubFilename, true, new HexDecoder);
//	RSAES_OAEP_SHA_Encryptor pub(pubFile);
//
//	RandomPool randPool;
//	randPool.Put((byte *) seed, strlen(seed));
//	string result;
//	StringSource(message, true,
//			new PK_EncryptorFilter(randPool, pub,
//					new HexEncoder(new StringSink(result))));
//
//	return result;
//}
//
////------------------------
//// RSA解密
////------------------------
//string RSADecryptString(const char *privFilename, const char *ciphertext) {
//	FileSource privFile(privFilename, true, new HexDecoder);
//	RandomPool & GlobalRNG();
//	RSAES_OAEP_SHA_Decryptor priv(privFile);
//	string result;
//	StringSource(ciphertext, true,
//			new HexDecoder(
//					new PK_DecryptorFilter(GlobalRNG(), priv,
//							new StringSink(result))));
//	return result;
//}
//
////------------------------
//// 定义全局的随机数池
////------------------------
//RandomPool & GlobalRNG() {
//	static RandomPool randomPool;
//	return randomPool;
//}
//
