#pragma once
#include<iostream>
#include<fstream>
using namespace std;

// kiem tra su ton tai cua file
bool CheckFileExitsting() {
	bool is_exist = true;
	fstream data_file;
	data_file.open("input.txt", ios::in);
	bool ret = data_file.fail();
	if (ret == true) {
		is_exist = false;
	}
	data_file.close();
	return is_exist();
}

class ConNguoi {
protected:
	char* hoten;
	char gioitinh;
	int namsinh, chieucao, cannang, thunhap;
public:
	ConNguoi() {
		void doc();
	}
};
