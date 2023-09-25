#include<conio.h>
#include<stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
 
struct SinhVien {
    int id;
    char ten[30];
    char msv[10];
    double diemTin;
    double diemNN;
    double diemTB = 0;
    char hocluc[10] = "-";
};
 
typedef SinhVien SV;
void nhap(SV &sv);
void nhapDS(SV a[], int n);
void tinhDTB(SV &sv);
void xeploai(SV &sv);
void sapxepTheoDTB(SV a[], int n);
void xuat(SV sv);
void xuatDS(SV a[], int n);
void timKiemTheoTen(SV a[], char ten[], int n);
void DTBcaonhat(SV a[], int n);
void DSthilai(SV a[], int n);

 
int main() {
    int key;
    SV arraySV[30];
    int n;
     
    do{
        printf("Nhap so luong sinh vien: "); scanf("%d", &n);
    }while(n <= 0);
    
    SV a[n];
    
    nhapDS(a, n);
 
    while(true) {
        cout << "\nCHUONG TRINH QUAN LY SINH VIEN\n";
        cout << "**  1. Hien thi danh sach sinh vien.\n";
        cout << "**  2. Danh sach sinh vien thi lai.\n";
        cout << "**  3. Danh sach sinh vien DTB cao nhat lop.\n";
        cout << "**  4. Sap xep sinh vien theo DTB (giam dan).\n";
        cout << "**  5. Tim kiem sinh vien theo ten.\n";
        cout << "**  0. Thoat\n";
        cout << "*******************************************************\n";
        cout << "Nhap tuy chon cua ban: ";
        cin >> key;
        
        switch(key){
    		case 1:
				cout << "\nDanh sach sinh vien:";
				cout <<"\nHo va ten\t\tMaSV\tTin\tNgNgu\tDiemTB\tXepLoai\n";
                xuatDS(a, n);
            	break;
				
			case 2:
				DSthilai(a, n);
            	break;
			
			case 3:
            	DTBcaonhat(a, n);
            	break;
				
			case 4:
				cout << "\nDanh sach sinh vien theo DTB giam dan la:\n";
                sapxepTheoDTB(arraySV, n);
                xuatDS(a, n);
                
            	break;
				
			case 5:
                char strTen[30];
                cout << "\nNhap ten sinh vien can tim: "; fflush(stdin); gets(strTen);
                timKiemTheoTen(a, strTen, n);
            	break;    
	        	
        	case 0:
                cout << "\nBan da chon thoat chuong trinh!";
                getch();
                return 0;
            default:
                cout << "\nKhong co chuc nang nay!";
                cout << "\nHay chon chuc nang trong hop menu.";
                break;
    	}

    }
}
  
void tinhDTB(SV &sv) {
    sv.diemTB = (sv.diemTin + sv.diemNN) / 2;    
}
 
void xeploai(SV &sv) {
    if(sv.diemTB >= 8) strcpy(sv.hocluc, "Gioi");
    else if(sv.diemTB >= 6.5) strcpy(sv.hocluc, "Kha");
    else if(sv.diemTB >= 5) strcpy(sv.hocluc, "Dat");
    else strcpy(sv.hocluc, "Khong dat");
}
  
void nhap(SV &sv) {
    cout << "\n Nhap ten: "; fflush(stdin); gets(sv.ten);
    cout << " Nhap msv: "; gets(sv.msv);
    cout << " Nhap diem Tin: "; cin >> sv.diemTin;
    cout << " Nhap diem Ngoai Ngu: "; cin >> sv.diemNN;
    tinhDTB(sv);
    xeploai(sv);
}
 
void nhapDS(SV a[], int n) {
    for(int i = 0; i< n; ++i){
        printf("\nNhap SV thu %d:", i+1);
        nhap(a[i]);
    }
}
 
 
void timKiemTheoTen(SV a[], char ten[], int n) {
    SV arrayFound[30];
    char tenSV[30];
    int found = 0;
    for(int i = 0; i < n; i++) {
        strcpy(tenSV, a[i].ten);
        if(strstr(strupr(tenSV), strupr(ten))) {
            arrayFound[found] = a[i];
            found++;
        }
    }
    xuatDS(arrayFound, found);
}
 
void xuat(SV sv) {
        printf(sv.ten);
        printf("\t\t%s", sv.msv);
        printf("\t%.2f\t%.2f", sv.diemTin, sv.diemNN);
        printf("\t%.2f", sv.diemTB);
        printf("\t%s", sv.hocluc); cout <<endl;

}


void xuatDS(SV a[], int n) {
	for(int i = 0;i < n;++i){
        xuat(a[i]);
    }
}
  
void sapxepTheoDTB(SV a[], int n) {
    //Sap xep theo DTB giam dan
    SV tmp;
    for(int i = 0;i < n-1;i++) {
        for(int j = i+1; j < n;j++) {
            if(a[i].diemTB < a[j].diemTB) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}


void DTBcaonhat(SV a[], int n) {
	double max;
	max = a[0].diemTB;
	for(int i = 0;i < n;++i){
        if (a[i].diemTB > max){
        	max = a[i].diemTB;
		};
    }
    
    cout << "\nDanh sach sinh vien co DTB cao nhat la:\n";
    cout <<"\nHo va ten\t\tMaSV\tTin\tNgNgu\tDiemTB\tXepLoai\n";
    for(int i = 0;i < n;++i){
        if (a[i].diemTB == max) {
        	xuat(a[i]);
		};
    }
    
}

void DSthilai(SV a[], int n) {
	cout << "\nDanh sach sinh vien phai thi lai la:\n";
    cout <<"\nHo va ten\t\tMaSV\tTin\tNgNgu\tDiemTB\tXepLoai\n";
	for(int i = 0;i < n;++i){
        if (a[i].diemTin < 5 || a [i].diemNN < 5) {
        	xuat(a[i]);
		};
    }
}
 

