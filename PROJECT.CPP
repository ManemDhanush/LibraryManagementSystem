#include<graphics.h>
#include<process.h>
#include<iomanip.h>
#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<string.h>

void CREATE_CIRCLE(int ,char*, char* , char*, char*);

class LIBRARY{
		char *Name_of_Book;
		char *Name_of_Author;
		int Book_No;
		char rent;

		public : LIBRARY()
			 { strcpy(Name_of_Book,"10 Ways to kill you ");
			   strcpy(Name_of_Author,"Yourself ");
			   Book_No=69;
			   rent='y';
			  }

			 void ADD();
			 void DELETE();
			 void DISPLAY();
			 void RENT();
			 void RETURN();
			 int getBook_No(){return Book_No; }
	     }L;

void LIBRARY::ADD()
{
   fstream f("LIBRARY.txt",ios::app,ios::out);

   char ch='y';

   while(ch=='y'||ch=='Y')
     {
	 cout<<"\n\nEnter Book No : ";
	 cin>>Book_No;

	 cout<<"\nEnter Name of Book : ";
	 gets(Name_of_Book);

	 cout<<"\nEnter Name of Author : ";
	 gets(Name_of_Author);

	 rent='y';

	 f.write((char*)&this,sizeof(this));

	 cout<<"\n\nDo you want to Enter More Books (y/n): ";
	 cin>>ch;

     }

   f.close();

}

void LIBRARY::DELETE()
{
   fstream f("LIBRARY.txt",ios::in);
   fstream f1("temp.txt",ios::out,ios::app);

   int u;

   cout<<"\n\nEnter Book No : ";
   cin>>u;

   int z=0;

   while(f.read((char*)&this,sizeof(this)))
       {
	   if(!(Book_No==u))
	     f1.write((char*)&this,sizeof(this));

	   else
	     z=1;
       }

   clearviewport();

   if(z==0)
     cout<<"\n\n\nBook Doesn't Exist ";

   else
     cout<<"\n\n\nBook Successfully Deleted !!";

   remove("LIBRARY.txt");
   rename("temp.txt","LIBRARY.txt");

   f.close();
}

void LIBRARY::DISPLAY()
{
   fstream f("LIBRARY.txt ",ios::in);

   cout<<"NAME OF BOOK"<<setw(20)<<"NAME OF AUTHOR"<<setw(20)<<"BOOK NO" <<setw(10)<<"AVAILABLE "<<setw(5)<<endl;

   while(f.read((char*)&this,sizeof(this)))
     {
       cout<<Name_of_Book<<setw(20)<<Name_of_Author<<setw(20)<<Book_No<<setw(10)<<rent<<setw(5)<<endl;

     }

   f.close();

}

char *p="Library Management System";
int n;

void LOAD()
{
  int l=getmaxx()/2,m=getmaxy()/2;

  int k=2;

  do{
       clearviewport();
       circle(l,m,l/2);
       outtextxy(l-30,m,"Loading--\  ");
       delay(1000);

       clearviewport();
       circle(l,m,l/2);
       outtextxy(l-30,m,"Loading--|  ");
       delay(1000);

       clearviewport();
       circle(l,m,l/2);
       outtextxy(l-30,m,"Loading--/  ");
       delay(1000);

       clearviewport();
       circle(l,m,l/2);
       outtextxy(l-30,m,"Loading---  ");
       delay(1000);

       clearviewport();
       circle(l,m,l/2);
       outtextxy(l-30,m,"Loading--\  ");
       delay(1000);

       k--;

    }while(k!=0);

}

void SEARCH()
{
   clearviewport();
   int l=getmaxx()/2,m=getmaxy()/2;

   LOAD();

   for(int i=l/2;i<3*l/2;i++)
     {
	clearviewport();
	circle(l,m,i);
	delay(25);
     }

   clearviewport();
   //SEARCH MATERIAL NOT DONE

}

void MODIFY()
{
   int v;

   CREATE_CIRCLE(3,"1.ADD","2.DELETE","3.DISPLAY","MODIFY");
   cout<<"Enter Choice : ";
   cin>>v;

   switch(v)
    {
      case 1: clearviewport();
	      L.ADD();
	      break;

      case 2: clearviewport();
	      L.DELETE();
	      break;

      case 3: clearviewport();
	      L.DISPLAY();
	      break;

    }
}

void LIBRARY::RENT()
{
   clearviewport();

   fstream f("LIBRARY.txt",ios::in||ios::out||ios::app);
   int y;

   cout<<"\n\n\nEnter Book no : ";
   cin>>y;

   while(f.read((char*)&this,sizeof(this)))
      {
	 if(Book_No==y)
	   {
	      rent='n';
	      f.seekp(-1*sizeof(this));
	      f.write((char*)&this,sizeof(this));

	   }
      }
}

void LIBRARY::RETURN()
{
   clearviewport();

   fstream f("LIBRARY.txt",ios::in||ios::out||ios::app);
   int y;

   cout<<"\n\n\nEnter Book no : ";
   cin>>y;

   while(f.read((char*)&this,sizeof(this)))
      {
	 if(Book_No==y)
	   {
	      rent='y';
	      f.seekp(-1*sizeof(this));
	      f.write((char*)&this,sizeof(this));

	   }
      }
}

void RENT_RETURN()
{
   int v;

   CREATE_CIRCLE(2,"1.RENT ","2.RETURN","asdas","RENT/RETURN");

   cout<<"Enter Choice : ";
   cin>>v;

   switch(v)
     {
	case 1: clearviewport();
		L.RENT();
		break;

	case 2: clearviewport();
		L.RETURN();
		break;

	default: ;
     }
}

void SWITCH()
{
   int l=getmaxx()/2,m=getmaxy()/2;

   switch(n)
     {
	 case 1: clearviewport();
		SEARCH();
		 break;

	 case 2: clearviewport();
		 MODIFY();
		 break;

	 case 3: clearviewport();
		 RENT_RETURN();
		 break;

	 case 4: clearviewport();
		 outtextxy(l-30,m,"Thanks for using!!");
		 delay(2000);
		 exit(0);

	 default : ;

     }
}

void Layout()
{
   int l=getmaxx()/2,m=getmaxy()/2;

   circle(l,m,100);                          //Primary Circle
   settextstyle(1,0,3);
   outtextxy(l-40,m-15,"Library");

   circle(l-250,m-50,50);               //Seconday Circle-1
   line(l-100,m,l-200,m-50);
   settextstyle(1,0,1);
   outtextxy(l-290,m-60,"1.SEARCH");

   circle(l+250,m-50,50);               //Seconday Circle-2
   line(l+100,m,l+200,m-50);
   settextstyle(1,0,1);
   outtextxy(l+210,m-60,"2.MODIFY");

   circle(l-200,m+150,50);               //Seconday Circle-3
   line(l-65,m+75,l-150,m+150);
   settextstyle(1,0,1);
   outtextxy(l-235,m+132,"3.RENT/");
   outtextxy(l-235,m+150,"RETURN");

   circle(l+200,m+150,50);               //Seconday Circle-4
   line(l+65,m+75,l+150,m+150);
   settextstyle(1,0,1);
   outtextxy(l+175,m+140,"4.EXIT");

   gotoxy(0,24);
   cout<<"Enter Choice:  ";
   cin>>n;

   SWITCH();
}


void CREATE_CIRCLE(int q,char *x, char *y, char *z,char *p)
{
   int l=getmaxx()/2,m=getmaxy()/2;

   for(int i=0;i<=m;i++)
     {
	clearviewport();
	circle(l,m-i,l/2);
	delay(1);
     }
   int h=60;

   if(q==3)
    h=40;

   outtextxy(l-h,40,p);

   int f=3*l/4;

   circle(l-f,m,50);
   line(l-f,m-50,l/2+45 ,m/2-8);
   outtextxy(l-f-30,m-15,x);


   circle(l+f,m,50);
   line(l+f,m-50,3*l/2-45,m/2-8);
   outtextxy(l+f-40,m-15,y);

   if(q==3)
    {
       circle(l,m+m/3,50);
       line(l,m-80,l,m+m/3-50);
       outtextxy(l-40,m+m/3-15,z);
    }
}

void Welcome_Screen()
{
   int l=getmaxx()/2,m=getmaxy()/2;

   int t;

   for(int i=100;i<=150;i++)
       {
	  t=i/8;

	  clearviewport();
	  rectangle(l-i,m-t,l+i,m+t);
	  delay(50);
       }

    for(i=0;i<175;i++)
      {
	 clearviewport();
	 rectangle(l-150,m-t-i,l+150,m+t-i);
	 outtextxy(l-4*strlen(p),m-strlen(p)/4-i,p);
	 delay(15);
      }

}

void main()
{
   int x=DETECT,y;

   initgraph(&x,&y,"C:\\TURBOC3\\BGI");

    Welcome_Screen();
HOME :   Layout();
//   CREATE_CIRCLE(3,"a","s","d");

//     Load();
   goto HOME;

}