
void gotoxy(int x,int y)
{
    for( i=0;i<x;i++)
        cout<<'\n';
    for( i=0;i<y;i++)
        cout<<' ';
}
 void welcome()
 {
     system("cls");
     for( i=0;i<336;i++)
        cout<<'_';

        gotoxy(5,70);
        cout<<"WELCOME TO 8085 SIMULATOR !";
        gotoxy(3,70);
        cout<<"PREPARED BY :-";
        gotoxy(3,85);
        cout<<"KRISHNA YADAV";
        for( i=0;i<336;i++)
        cout<<'_';

     system("pause");
     system("cls");
 }

 void argcheck(int argc, char *argv[], bool *debugger, bool *incode)
 {
     if(argc>3)
    {
        cout<<"\n\n\t ERROR : In Command Line Arguments...!";
        exit(0);
    }
    else
        for(i=1;i<argc;i++)
        {
            if(!strcmpi(argv[i],"DEBUGGER"))
                *debugger=true;
            else
            {
                *incode=true;
                strcpy(name,argv[i]);
            }
        }
 }

 int HtoD(string s)
{
    int b[20]={0},sum=0,n=0;
    int l=s.length();

    for(i=0;i<l;i++)
    {
        if(s[i]>64 &&s[i]<71)
             n=s[i]-55;
        else
            n=s[i]-48;
        int k=4*(i+1);
        while(n!=1 && n!=0)
        {
            b[--k]=n%2;
            n=n/2;
        }
        b[--k]=n;
    }
    for(i=0;i<l*2;i++)
    {
        int tmp=b[i];
        b[i]=b[(l*4)-1-i];
        b[(l*4)-1-i]=tmp;
    }
    for(int j=0;j<l*4;j++)
    {

            if(b[j]==1)
                sum+=pow(2,j);
    }
    return sum;
}

string DtoH(int i)
{

    char  s[88];
    itoa(i,s,16);
    int j;
    for( j=0;s[j]!='\0';j++)
    {
        if(s[j]>96&&s[j]<103)
        {
            s[j]=s[j]-32;
        }
    }

    if(j==1)
    {
        s[1]=s[0];
        s[0]='0';
        s[2] = '\0';
    }
    string str(s);
    return str;
}

string DtoHM(int i)
{

    char  s[88];
    itoa(i,s,16);
    int j;
    for( j=0;s[j]!='\0';j++)
    {
        if(s[j]>96&&s[j]<103)
        {
            s[j]=s[j]-32;
        }
    }

    if(j==2)
    {
        s[4]='\0';
        s[3]=s[1];
        s[2]=s[0];
        s[0] ='0';
        s[1]='0';
    }
    else if(j==1)
    {
        s[4]='\0';
        s[3]=s[0];
        s[2]='0';
        s[0] ='0';
        s[1]='0';
    }
    string str(s);
    return str;
}

string inst_size(string cmd)
{
    if(cmd == "MOV"||cmd == "ADD"||cmd == "SBB"||cmd == "CMA"||cmd == "HLT"||cmd == "SUB"||cmd == "STAX"||cmd == "PUSH"||cmd=="XRA"||cmd=="RLC"||cmd=="RRC"||cmd=="RAR"||cmd=="RAL"||cmd=="LDAX"||cmd=="XCHG"||cmd=="ADC"||cmd=="DAD"||cmd == "INX"||cmd=="INR"||cmd=="DAA"||cmd=="DCR"||cmd=="DCX"||cmd=="ORA"||cmd=="ANA"||cmd=="XRA"||cmd=="CMC"||cmd=="STC"||cmd=="CMP"||cmd=="POP"||cmd=="SPHL"||cmd=="XTHL"||cmd == "POP")
        return "1";
    else if(cmd == "ADI" ||cmd == "SBI"||cmd == "MVI"||cmd == "OUT"||cmd == "IN"||cmd=="ACI"||cmd=="SUI"||cmd=="SBI"||cmd=="ORI"||cmd=="ANI"||cmd=="XRI"||cmd=="CPI")
        return "2";
    else if(cmd == "LDA" ||cmd == "STA"||cmd == "LXI"||cmd == "LHLD"||cmd == "JC"||cmd=="JNC"||cmd=="JMP"||cmd=="JZ"||cmd=="JNZ"||cmd=="JPE"||cmd=="JPO" ||cmd == "JP"||cmd == "JM")
        return "3";
    else if(cmd=="SET")
        return "4";
    else
        return "0";
}

void help()
{
    cout<<"\n\n\t\t\tDEBUGGER SHORTCUTS\n";
    cout<<"\n\n\t1. break or b `line no`:- It will set break point on given line number."<<endl;
    cout<<"\n\n\t2. run or r :- Run the program until it ends or breakpoint encountered."<<endl;
    cout<<"\n\n\t3. step or s :- It will run the program one instruction at a time."<<endl;
    cout<<"\n\n\t4. print or p:- It prints the value of register or memory location.\n\t   For Ex :  p A will print the value of ";
    cout<<"register A.\n\t   p x2500 will print the value at memory location x2500 if any."<<endl;
    cout<<"\n\n\t5. quit or q:- quits the debugger."<<endl;

}
