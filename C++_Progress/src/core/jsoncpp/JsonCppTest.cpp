/*
 * JsonCppTest.cpp
 *
 *  Created on: 2015-12-12
 *      Author: ruibiao
 */

#include "JsonCppTest.h"

JsonCppTest::JsonCppTest() {

}

JsonCppTest::~JsonCppTest() {
}

void JsonCppTest::fromJsonString() {
	std::string strValue =
			" {\"key1\":\"value1\",\"array\":[ {\"key2\":\"value2\"},{\"key2\":\"value3\"},{\"key2\":\"value4\"}]}";

	Json::Reader reader;
	Json::Value value;
	if (reader.parse(strValue, value)) {
		std::string out = value["key1"].asString();
		std::cout << out << std::endl;
		const Json::Value arrayObj = value["array"];
		for (int i = 0; i < arrayObj.size(); i++) {
			out = arrayObj[i]["key2"].asString();
			std::cout << out << "\t";
		}
	}
}

void JsonCppTest::toJsonString() {
	Json::Value root;
	Json::Value arrayObj;
	Json::Value item;
	for (int i = 0; i < 10; i++) {
		item["key"] = i;
		arrayObj.append(item);
	}

	root["key1"] = "value1";
	root["key2"] = "value2";
	root["array"] = arrayObj;
	std::string out = root.toStyledString();
	std::cout << out << std::endl;
}

void JsonCppTest::deleteJsonString() {
	std::string strContent = "{\"key\":\"1\",\"name\":\"test\"}";
	Json::Reader reader;
	Json::Value value;
	if (reader.parse(strContent, value)) {
		Json::Value root = value;
		root.removeMember("key");
		std::cout << root.toStyledString() << std::endl;
	}
}
