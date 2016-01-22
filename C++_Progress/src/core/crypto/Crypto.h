/*
 * Crypto.h
 *
 *  Created on: 2015-12-29
 *      Author: ruibiao
 */

#ifndef CRYPTO_H_
#define CRYPTO_H_
#include <iostream>
#include <cryptopp/des.h>
#include <cryptopp/aes.h>
//#include <cryptopp/randpool.h>
//#include <cryptopp/rsa.h>
//#include <cryptopp/hex.h>
//#include <cryptopp/files.h>

#pragma comment( lib, "cryptlib.lib" )
using namespace std;
using namespace CryptoPP;
class Crypto {
public:
	Crypto();
	virtual ~Crypto();
	void des(); //对称加密
	void aes(); //对称加密
	void rsa(); //非对称加密
	void sha(); //散列算法：（SHA系列，我们熟悉的MD5等）
};

#endif /* CRYPTO_H_ */
