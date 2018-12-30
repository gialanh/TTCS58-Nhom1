#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;
 ifstream f("input3.txt");
 ofstream c("output3.txt ");
 struct nhanvien{
 	int Manhanvien ;
 	int Tienluong;
 	string Holot;
 	string Ten;
 	int n ;
 };
 
 
 void nhap(nhanvien ds[] ,int n )
 {
 	cout<< "nhap so luong sinh vien:" ; cin >>n;
 	 for (int i=0 ;i<n ; i++)
 	      {
 	      	cout<<"------------------" <<endl ;
 	      	cout<<"nhap ma nhan vien:" <<endl ;
 	      	cin >> ds[i].Manhanvien ;
 	      	cout<<"nhap ho lot nhan vien:" <<endl ;
 	      	getline(cin,ds[i].Holot) ;
 	      	cout<<"nhap ten nhan vien :" <<endl ;
 	      	getline(cin,ds[i].Ten) ;
 	      	cout<<"nhap tien luong nhan vien:" <<endl ;
 	      	cin>> ds[i].Tienluong ;
		   }
		fstream s;
		s.open("D:\\input3.txt",ios::in);
		s>>n;
		
		//<<thong tin file duoc luu vao << endl ;
		for(int i=0 ; i<n ; i++)
		 {
		 	 s<<ds[i].Manhanvien << "\n " ;
		 	 s<<ds[i].Holot  <<" \n" ;
		 	 s<<ds[i].Ten <<"\n " ;
		 	 s<<ds[i].Tienluong <<"\n " ;
		 	 
		 }
		 s.close() ;
		 
 }
  void timkiem(nhanvien ds[] ,int n){
 	for(int i=0; i < n; i++)
	 {	cout<<"------ nhan vien thu i -------: "<< i; 
 		cout<<"\n "<< ds[i].Manhanvien; 
 		cout<<"\n "<< ds[i].Holot;   
 		cout<<"\n "<< ds[i].Ten;  
 		cout<<"\n "<< ds[i].Tienluong<< endl;
 	}
 	
 }
 void luongmaxmin(nhanvien ds[],int n)
 {
 	 cout<<"tiên luong nhan vien cao nhat :"  <<endl ;
 	int s1=ds[0].Tienluong ; //gan s1 =  ds tien luong thu 1
 	int t1;
 	  for(int i=0 ;i<n ; i++)
 	  {
 	  	  if(s1<=ds[i].Tienluong)   //so sanh 
 	  	    { 
 	  	        s1=ds[i].Tienluong ;   //gan s1=ds tien luong thu i
 	  	        t1=i;
			   }
	   }
	   cout<<" tien luong nhan vien thap nhat :" <<endl ;
	   
	int s2 =ds[0].Tienluong ; //....................
	int t2 ;
	    for(int i=0; i< n ; i++)
	    {
	    	 if(s2>=ds[i].Tienluong)
	    	 {
	    	 	 s2=ds[i].Tienluong ;
	    	 	 t2=i ;
			 }
		}
 	
 }
 /* void sapxep(nhanvien ds[] ,int n)
 {  int tam;
 	  for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            {
            	if(ds[i].Ten.compare(ds[j].Ten)>0){
            		tam=ds[i];
            		ds[i]=ds[j] ;
            		ds[j]=tam; 
				}
				else
				if(ds[i].Ten.compare(ds[j].Ten)==0)
				{
					if(ds[i].Holot.compare(ds[j].Holot)>0){
						tam=ds[i];
						ds[i]=ds[j];
						ds[j]=tam;
					}
				}
			}
 } */
 void showmenu(nhanvien ds[] ,int n)
 {
 	int chon ;
 	cout<< "1.nhap ma nhan vien"<< endl;
 	cout<< "2.tim nhan vien"<< endl;
 	cout<< "3.nhan vien co luong cao nhat va thap nhat"<< endl;
 	cout<< "4.xap sep nhan vien"<< endl;
 //	cout<< "5. luu ket qua"<< endl;
 	cout<< "6.exit "<<endl;
 	
 	 	cout<< "hay nhan chon yeu cau"<< endl;
 
 	switch(chon){
 		case 1:
 			system("cls");
 		  cout<< "nhap so luong nhan vien" ;
 		  cin>> n ;
			   {
           	    cout << "Exit" << endl;
       			}
            break;
 		case 2:
 			cout<<" nhanvien tim duoc la :" ;
         timkiem(ds,n) ;
          
            break;
        case 3:
           cout<<"danh sanh nhan vien luong cao nhat:" ; << endl ;
		   cout<< "danh sach nhan vien luong thap nhat" ;<<endl ;
             cin>> luongmaxmin(ds,n) ;
           
                cout << "Exited" << endl;
            
            break;
        case 4:
            
            cout << "sau khi sap xep" << endl;
             sapxep(ds,n) ;
                cout << "Exited" << endl;
            
            break;
       /* case 5:
       cout<<"luu ket qua vao file " << endl ;
       break ;
        */
        case 6:
            	cout << "\t\t\t  Exit" << endl;
            	break;
	 }
 }
 
 int main()
 {
 	int n;
 	nhanvien ds();
 	showmenu(ds ,n ) ;
 	getch() ;
 	return 0 ;
 }

