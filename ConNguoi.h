
#include<iostream>
#include"TieuChi.cpp"

using namespace std;
class ConNguoi {
  private:         
    //thong tin
    int age,earning,weight,height;         
    string name,sex,address;
    //tieuchi: min max 
    TieuChi tcage,tcweight;
    int sumAver; //tong diem diem thap nhat can duoc

  public:
      ConNguoi() {

      }
      void SetInfo(string name, int age, string sex) {
          this->name = name;
          this->age = age;
          this->sex = sex;

      }
      void SetTc(TieuChi tcage) {  
          this->tcage = tcage;//tieu chi ve tuoi
      }
      void printData() {
          cout << this->name << " " << this->sex << " " << this->age<< " " << endl;
      }
    //----kiem tra a du dieu kien de ghep doi tuong hien tai this hay ko
    bool checkghep(ConNguoi a) { 
        int sumtemp = 0;
        //----age: neu tieu chi thoa thi duoc cong diem
        if (a.age >= this->tcage.min && a.age <= this->tcage.max) sumtemp = a.tcage.mark;
        //----weight,height,earning
        if (sumtemp >= a.sumAver) return true;
        else return false;
    }
    //----
    bool ghepdoi(ConNguoi a, ConNguoi b) {
        if(checkghep(a,b) && checkghep(b,a))
            return true;
        else return false;
    }
};

//// kiem tra su ton tai cua file
//bool CheckFileExitsting() {
//	bool is_exist = true;
//	fstream data_file;
//	data_file.open("input.txt", ios::in);
//	bool ret = data_file.fail();
//	if (ret == true) {
//		is_exist = false;
//	}
//	data_file.close();
//	return is_exist();
//}
//
//class ConNguoi {
//protected:
//	char* hoten;
//	char gioitinh;
//	int namsinh, chieucao, cannang, thunhap;
//public:
//	ConNguoi() {
//		void doc();
//	}
//};


