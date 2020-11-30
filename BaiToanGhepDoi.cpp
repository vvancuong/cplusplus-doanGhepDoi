#include "ConNguoi.h"
#include <iostream>  
#include <stdio.h>  
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

#define maxN 7
using namespace std;

//doi tuong nam va nu
ConNguoi nu[1000];
ConNguoi nam[1000];
int sonu=0, sonam=0; //Na so nu, Nb so nam
//------
int c[maxN][maxN] = {  //do thi Nu ghep Nam
   {0, 0, 0, 0, 0, 0, 0},
   {0, 1, 0, 0, 1, 0, 0},
   {0, 1, 1, 0, 1, 0, 0},
   {0, 0, 1, 1, 0, 0, 0},
   {0, 0, 1, 1, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0}
};
//------
string arrTc[100];
int numTc;
int A[maxN], B[maxN], trace[maxN];
int N, lj;
bool ok;
//-------- 

void tang_canh(int j) {  // Đổi mầu các cạnh trên đường mở để tăng số cạnh của bộ ghép
    int i, p = 0;
    while (j != 0) {
        i = trace[j];
        p = A[i];
        A[i] = j;
        B[j] = i;
        j = p;
    }

}

// Tìm một đường mở từ đỉnh nhạt i bên X, kết thúc ở đỉnh nhạt lj bên Y
void tim_duong_mo(int i) {  //i nu ben X:  ghep X voi Y; cách 2: BFS  sử queue de lam.
    // cac dinh ben nam 
    for (int j = 1; j <= sonam; j++)

        if ((c[i][j] == 1) && (trace[j] == 0)) { //Connguoi::ghepdoi(nu[i],nam[j])==true 
         
            trace[j] = i;
            // neu j chua ghep => tim duoc duong mo
            if (B[j] == 0) {
                ok = true; //tim duoc duong mo
                lj = j; // dinh cuoi cung tim duoc ben nam la j
                return;
            }
            //j da ghep
            else tim_duong_mo(B[j]); // Đệ quy kéo dài đường mở

        }

}

void thuc_hien() {
    // gan cho chua co nu nao duoc ghep
    for (int j = 1; j <= sonu; j++)
        A[j] == 0;

    // Nu nao chua ghep thi ghep
    for (int i = 1; i <= sonu; i++)  
        if (A[i] == 0) {
            // luu vet duong di
            for (int j = 1; j <= sonam; j++)
                trace[j] = 0;
            ok = false; // chưa tìm được đường mở
            
            // Tìm đường mở từ i
            tim_duong_mo(i); 

            if (ok) tang_canh(lj); // Tìm được đường mở kết thúc tại đỉnh nhạt lj, thì tăng cạnh

        }

}

void tachchuoi(string str, char c) {
    numTc = 0;
    int vt = 0;
    for (int i = 0; i < str.length();i++)
    if (str.at(i) == c) {
        arrTc[numTc] = str.substr(vt, (i - vt));
        numTc++;
        vt = i + 1;
    }
    //them phan tu cuoi
    arrTc[numTc] = str.substr(vt, (str.length() - vt));
    numTc++;
}
string rmChar(string str,char c)
{ 
    string temp;
    for (int i = 0; i<str.length(); i++)
        if (str[i] !=c) temp = temp + str[i];
    return temp;
}

//xoa ky tu trang o 2 dau
string rmTrim(string str)
{
    string temp;
    int i, j;
    for (i = 0; i < str.length(); i++)
        if (str[i] != ' ') break;
    for (j = str.length()-1; j>=0; i--)
        if (str[j] != ' ') break;
    for (int e = i; e <= j; e++)
        temp = temp + str[e];

    return temp;
}

void docDulieu() {
    string str1, str2, str3;
    // Read from the text file
    ifstream MyReadFile("input.txt");

    // Use a while loop together with the getline() function to read the file line by line

    while (getline(MyReadFile, str1)) {//str1 thong tin
        getline(MyReadFile, str2);//tieu chi
        getline(MyReadFile, str3);//AveMark
        //------
        tachchuoi(str1, ';'); 
        if (rmTrim(arrTc[1]) == "Nu") { 
            sonu++;
            TieuChi temptc;
            temptc.name = "age";temptc.min = 10;temptc.max = 20;temptc.mark = 5;
            nu[sonu].SetInfo(rmTrim(arrTc[0]), stoi(rmTrim(arrTc[2])),"Nu");//stoi de doi string to int
            nu[sonu].SetTc(temptc);
            
        }
        else { 
            sonam++;
            TieuChi temptc;
            temptc.name = "age";temptc.min = 10;temptc.max = 20;temptc.mark = 5;
            //gan thong tin 
            nam[sonam].SetInfo(rmTrim(arrTc[0]), stoi(rmTrim(arrTc[2])), "Nam");
            nam[sonam].SetTc(temptc);
            
        } 
    }


    // Close the file
    MyReadFile.close();    
}
void test() {
    int t1 = stoi("1111");
    int t2 = t1+1;
    //cout << t2;
    cout << "Xuat thu doi tuong" << endl;
    for (int i = 1;i <= sonam; i++) nam[i].printData();
    for (int i = 1;i <= sonu; i++) nu[i].printData();
}



int main() {
    N = 4;
    docDulieu();
    test();
    thuc_hien();

    for (int i = 1; i <= sonu; i++)  // Hiện các cạnh của bộ ghép cực đại
       if (A[i] > 0) cout << i << "-" << A[i] << endl; //nu[i].ten va nam[A[i]].ten ......

    return 0;

}
