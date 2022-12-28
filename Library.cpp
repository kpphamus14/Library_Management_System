#include <iostream>
#include <iomanip>
#include <string.h>
#include <cstring>

using namespace std;

int DANG_NHAP_THANH_CONG = 0;
char TEN_NGUOI_DUNG[50];
char MK_NguoiDung_Nhap[50];

struct date
{
	int ngay;
	int thang;
	int nam;
};

struct NguoiDung
{
	char ten_dang_nhap[50];
	char password[50];
	char ho_ten[50];
	date ngaysinh;
	char cmnd[10];
	int gioi_tinh;
	int tinh_trang;
	int loai_nguoi_dung;
};

void printdate(date ntn)
{
	cout << ntn.ngay << "-" << ntn.thang << "-" << ntn.nam;
}

void InNguoiDung(NguoiDung nd)
{
	cout << "User Name" << "      " << "Name" << "         " << "Ngay Sinh" <<
		"       " << "cmnd" << "      " << "Gioi Tinh" << "     " << "Tinh Trang" << "   " << "Type" << endl;

	cout << nd.ten_dang_nhap <<"     "<< setw(-15) << nd.ho_ten << setw(7);
	printdate(nd.ngaysinh);
	cout << setw(13) << nd.cmnd << setw(10) << nd.gioi_tinh << setw(12) <<
		nd.tinh_trang << setw(12) << nd.loai_nguoi_dung;

}

void XuatMang(NguoiDung nd[10], int n)
{
	cout << "User Name" << "      " << "Name" << "         " << "Ngay Sinh" <<
		"       " << "cmnd" << "      " << "Gioi Tinh"<< "     " << "Tinh Trang" << "   " << "Type" << endl;
	for (int i = 0; i < n; i++)
	{
		InNguoiDung(nd[i]);
		cout << endl;
	}
}

void DangNhap(NguoiDung nd[10], int n, char TEN_NGUOI_DUNG[50])
{
	char username[50];
	char password[50];


		cout << "Nhap Ten Dang Nhap: " << endl;
		cin >> username;
		cout << "Nhap Mat Khau: " << endl;
		cin >> password;

		for (int i = 0; i < n; i++)
		{
			char* p = strstr(nd[i].ten_dang_nhap, username);
			if (p)
			{
				char* o = strstr(nd[i].password, password);
				if (o)
				{
					DANG_NHAP_THANH_CONG = 1;
					strcpy(TEN_NGUOI_DUNG, username);
				}
			}
		}

}

int Kiem_Tra_2_Inputs(char MK_NguoiDung_Nhap[50])
{
	char username[50];
	char Mat_Khau_Cu_lan1[50];
	char Mat_Khau_Cu_lan2[50];
	int kt = 0;

	cout << "Nhap Mat Khau Cu Lan 1: " << endl;
	cin >> Mat_Khau_Cu_lan1;

	cout << "Nhap Mat Khau Cu Lan 2: " << endl;
	cin >> Mat_Khau_Cu_lan2;

	int len1 = strlen(Mat_Khau_Cu_lan1);
	int len2 = strlen(Mat_Khau_Cu_lan2);

	if (len1 == len2)
	{
		for (int i = 0; i < len1; i++)
		{
			if (Mat_Khau_Cu_lan1[i] == Mat_Khau_Cu_lan2[i])
			{
				kt = 1;
			}
			else
			{
				kt = 0;
				break;
			}
		}
	}
	else
	{
		return kt;
	}
	if (kt == 1)
	{
		strcpy(MK_NguoiDung_Nhap, Mat_Khau_Cu_lan1);
	}
	return kt;
}

int KT_Input_VS_MatKhauCu(NguoiDung nd[10], int n, char TEN_NGUOI_DUNG[50], char MK_NguoiDung_Nhap[50])
{
	int kt = 0;
	for (int i = 0; i < n; i++)
	{
			char* p = strstr(nd[i].ten_dang_nhap, TEN_NGUOI_DUNG);
			if (p)
			{
				char* o = strstr(nd[i].password, MK_NguoiDung_Nhap);
				if (o)
				{
					kt = 1;
				}
			}
	}
	return kt;
}

void DoiMatKhau(NguoiDung nd[10], int n, char TEN_NGUOI_DUNG[50])
{
	char new_password[50];
	cout << "Nhap Mat Khau Moi: " << endl;
	cin >> new_password;
	for (int i = 0; i < n; i++)
	{
		char* p = strstr(nd[i].ten_dang_nhap, TEN_NGUOI_DUNG);
		if (p)
		{
			strcpy(nd[i].password, new_password);
			
		}
	}
}

int main()
{
	NguoiDung nd[10];
	int n = 3;
	nd[0] = { "kppham","abcd","Nguyen Van A",{23,3,1998},"21451243",1,1,0 };
	nd[1] = { "admin1","1234","Bui Minh Thuy",{19,9,1993},"23847513",1,1,1 };
	nd[2] = { "user12","7896","Pham Phu Khang",{11,1,2000},"11111111",0,0,0 };


	//XuatMang(nd,n);

	int menu;
	do {
		cout << "*****Phan Mem Quan Ly Thu Vien*****" << endl;
		cout << "1. Quan Ly Nguoi Dung" << endl;
		cout << "2. Quan Ly Doc Gia" << endl;
		cout << "-----Chon Chuc Nang-----" << endl;
		cin >> menu;

		switch (menu)
		{
			//nguoi dung
			case 1:
				int menu_con;
				do
				{
					cout << "-----Quan Ly Nguoi Dung-----" << endl;
					cout << "1. Dang Nhap" << endl;
					cout << "2. Dang Xuat" << endl;
					cout << "3. Doi Mat Khau" << endl;
	
					cout << "Chon Chuc Nang Quan Ly Nguoi Dung" << endl;
					cin >> menu_con;

					switch (menu_con)
					{
					case 1:
						DangNhap(nd, n,TEN_NGUOI_DUNG);
						if (DANG_NHAP_THANH_CONG == 1)
						{
							cout << "Dang Nhap Thanh Cong" << endl;

						}
						else
						{
							cout << "Dang Nhap That Bai" << endl;
						}
						break;
					case 2:
						if (DANG_NHAP_THANH_CONG == 1)
						{
							cout << "Dang Xuat Thanh Cong" << endl;
							DANG_NHAP_THANH_CONG = 0;
							strcpy( TEN_NGUOI_DUNG, "");
						}
						else
						{
							cout << "Chua Dang Nhap" << endl;
						}
						break;
					case 3:
						if (DANG_NHAP_THANH_CONG == 1)
						{
							int kt_2_inputs;
							int kt_input_vs_mkc;
							
							kt_2_inputs = Kiem_Tra_2_Inputs(MK_NguoiDung_Nhap);
							kt_input_vs_mkc = KT_Input_VS_MatKhauCu(nd, n, TEN_NGUOI_DUNG, MK_NguoiDung_Nhap);
							
							if (kt_2_inputs == 1 && kt_input_vs_mkc==1)
							{
								DoiMatKhau(nd,n,TEN_NGUOI_DUNG);
								strcpy(MK_NguoiDung_Nhap, "");
								cout << "Doi Mat Khau Thanh Cong" << endl;
							}
							else
							{
								cout << "Mat Khau Cu Khong Dung. Vui Long Dang Nhap Lai!" << endl;
							}
						}
						break;
					}
				} while (menu_con != 0);
				break;

			//Doc gia
			case 2:
				cout << "-----Quan Ly Doc Gia-----" << endl;
				break;
				
			default:
				break;

		}

	} while (menu != 0);

	return 0;
}