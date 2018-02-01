#include "header.h"
#include "func.cpp"
#include "updateflag.cpp"
#include "datatransfer.cpp"
#include "logical.cpp"
#include "branching.cpp"
#include "arithmatic.cpp"
#include "compile.cpp"
#include "print.cpp"


int main(int argc,char *argv[])
{
    //welcome();

    bool debugger=false,incode=false;

    argcheck(argc,argv,&debugger,&incode);

    int j;

    if(!incode)
    {
        strcpy(name,"input.txt");
        fstream fout;
            fout.open(name,ios::in|ios::out|ios::trunc);

        cout<<"\n\n\t Please Enter The 8085 Program...\n\n\t Note: Use 'EOF' TO Terminate\tBE AWARE! Backspace Is Disabled \n";
        st:
        cout<<"\n\n\tStarting Location : ";
        cin>>start;

        j=0;
        if(start.length()!=4)
        {
            cout<<"\n\n\t Please Enter 16 bit Memory Location In Hexadecimal Format ...";
            goto st;
        }
        while(j<start.length())
        {
            if(!((start[j]>=48&&start[j]<=57)||(start[j]>=65&&start[j]<=70)||(start[j]>=97&&start[j]<=102)))
            {
                cout<<"\n\n\t Invalid Memory Location...!";
                goto st;
            }
            ++j;
        }
        if(!(start>="2000"&&start<="4000"))
        {
            cout<<"\n\n\t ERROR : 8085 Microprocessor Memory is limited in range [2000 , 4000] ...";
            goto st;
        }

        j=0;

        pc=start;

        bool flag = true;
        while(flag)
        {
            locctr=pc;

            cout<<"\n\n\t"<<locctr<<" ";

            char ch;
            i=0;
            line="";
            while(!(line[i-3]=='E'&&line[i-2]=='O'&&line[i-1]=='F'))
            {
                ch=getche();
                if(isalpha(ch)&&islower(ch))
                    ch=ch-32;
                if(isalnum(int(ch))||ch==','||ch==' ')
                    line+=ch;

                if(ch==13)
                    break;
                i++;


            }
            if(line[i-3]=='E'&&line[i-2]=='O'&&line[i-1]=='F')
                flag=false;

                for(int k=0;line[k]!=0;k++)
                if(line[k]<=122 && line[k]>=97)
                    line[k]-=32;

            i = 0;
            istringstream iss(line);
            do
            {
                string subs;
                iss >> subs;
                cmd[i++] = subs;
            }while (iss);

            if(HtoD(inst_size(cmd[0])))
            {
                p[j].inst=line;
                p[j].memloc=locctr;
                p[j].b=false;
                int k=0;
                while(line[k])
                    fout.put(line[k++]);

                fout<<endl;
                ++j;
            }
            else
                if(cmd[0]!="EOF")
                    cout<<"\n\n\t ERROR : 404 ! INSTRUCTION NOT FOUND !....LINE NOT RECORDED THUS HAS NO EFFECT";


            pc=DtoH(HtoD(locctr)+HtoD(inst_size(cmd[0])));

            if(flag==false)
            {
                p[j].inst="HLT";
                p[j].memloc=pc;
                p[j].b=false;
            }

        }
        fout.close();
        END=p[j-1].memloc;
    }

    else
    {
        ifstream fin;

        fin.open(name,ios::in);

       if(!fin.is_open())
        {
            cout<<"\n\n\t File Not Found...";
            return 0;
        }

        fin.seekg(0,ios::end);

        if(fin.tellg()==0)
        {
            cout<<"\n\n\t Empty FILE...";
            fin.close();
            return 0;
        }

        fin.close();

        cout<<"\n\n\t Program In File  : \n\n";

        fin.open(name,ios::in);

        j=0;

            char ch;
            line = "";
            pc=start;


        while(getline(fin,line))
        {
            bool erflag=false;
            for(int k=0;line[k]!=0;k++)
            {
                if(line[k]<=122 && line[k]>=97)
                    line[k]-=32;

                if(!isalnum(int(ch))&&!ch==','&&!ch==' ')
                {
                    erflag=true;
                    break;
                }
            }

            if(erflag)
            {
                cout<<"\t\t\t ERROR : 404 ! INSTRUCTION NOT FOUND !....LINE NOT RECORDED THUS HAS NO EFFECT\n\n";
                continue;
            }
            locctr=pc;

            i = 0;
            istringstream iss(line);
            do
            {
                string subs;
                iss >> subs;
                cmd[i++] = subs;
            }while (iss);

            pc=DtoHM(HtoD(locctr)+HtoD(inst_size(cmd[0])));

            if(HtoD(inst_size(cmd[0])))
            {
                    cout<<locctr<<"\t"<<line<<endl;

                p[j].inst=line;
                p[j].memloc=locctr;
                p[j].b=false;
                ++j;
            }
            else
                cout<<"\t\t\t ERROR : 404 ! INSTRUCTION NOT FOUND !....LINE NOT RECORDED THUS HAS NO EFFECT\n\n";
        }

        END=p[j-1].memloc;
    }
    index=0;

    if(debugger)
    {
        cout<<"\n\n\t DEBUGGER MODE ON...!";
        help();

        do
        {
            cout<<"\n\n\t\t Enter Your Choice : ";
            getline(cin,deb);

            for(int k=0;deb[k]!='\0';k++)
                    if(deb[k]<=122 && deb[k]>=97)
                        deb[k]-=32;

            istringstream iss(deb);

            if(deb[0]=='B'||deb.substr(0,5)=="BREAK")
            {
                string brkpt;
                int count=0;

                    iss>>brkpt;
                    iss>>brkpt;

                if(brkpt.length()==4)
                {
                    bool f=true;
                    for(int i=0;p[i].memloc!=END;i++)
                        if(p[i].memloc==brkpt)
                        {
                            p[i].b=true;
                            f=false;
                            cout<<"\n\n\t Break Point Applied Successfully";
                            break;
                        }

                    if(f)
                        cout<<"\n\n\t ERROR : Invalid Memory Address";
                }
                else if(brkpt.length()<4)
                {
                    bool f=false;

                    int i=-1;
                    while(++i<j);

                    for(int h=0;h<brkpt.length();h++)
                            if(!(brkpt[h]>='0'&&brkpt[h]<='9'))
                            {
                                f=true;
                                break;
                            }
                    if(f)
                        cout<<"\n\n\t ERROR : Invalid Line Number...";

                    else
                    {
                        int i=0,num=0;
                        while(brkpt[i]>='0'&&brkpt[i]<='9')
                        {
                            num*=10;
                            num+=int(brkpt[i])%48;
                            i++;
                        }
                        if(num<j&&num>0)
                        {
                            p[num].b=true;
                            cout<<"\n\n\t Break Point Applied Successfully At Line : "<<num;
                        }
                        else
                            cout<<"\n\n\t ERROR : Invalid RValue..."<<brkpt[i]<<"."<<num<<".";

                    }
                }
                else
                    cout<<"\n\n\t ERROR : Invalid RValue...";

            }

            else if (deb=="R"||deb=="RUN")
            {
                index=0;
                while(p[index].memloc!=END&&p[index].b==false)
                {
                    compile();
                    ++index;
                }
                PRINT_VALUES();
                return 0;
            }
            else if(deb=="S"||deb=="STEP")
            {
                index = 0;
                cout<<"\n\n\t Please Hit Any Key To Run Interpreter... ";

                while(p[index].memloc!=END&&p[index].b==false)
                {   getch();
                    compile();

                    cout<<"\n\n\t\t\t  Output After Execution of Line No "<<index+1<<" : "<<endl<<endl;
                    PRINT_VALUES();
                    ++index;

                    if(p[index].b)
                        cout<<"\n\n  This Line Has A Breakpoint "<<endl;
                }
                if(index==0)
                    cout<<"Breakpoint Encountered at First Line "<<p[index].memloc<<" "<<END<<" "<<p[index].b<<endl;


                return 0;
            }

            else if(deb[0]=='P'||deb.substr(0,5)=="PRINT")
            {
                string print;
                iss>>print;
                iss>>print;

                index=0;
                while(p[index].memloc!=END&&p[index].b==false)
                {
                    compile();
                    ++index;
                }

                if(print=="A")
                    cout<<"\n\n\t Register A : "<<A;
                else if(print=="B")
                    cout<<"\n\n\t Register B : "<<B;
                else if(print=="C")
                    cout<<"\n\n\t Register C : "<<C;
                else if(print=="D")
                    cout<<"\n\n\t Register D : "<<D;
                else if(print=="E")
                    cout<<"\n\n\t Register E : "<<E;
                else if(print=="H")
                    cout<<"\n\n\t Register H : "<<H;
                else if(print=="L")
                    cout<<"\n\n\t Register L : "<<L;
                else
                {

                    bool fg = true;

                    for(int f=0;f<memoindex;f++)
                    {
                        if((memo[f].loc==print)||(print[0]=='X'&&memo[f].loc==print.substr(1,4)))
                        {
                            fg=false;
                            cout<<"\n\n\t Value At Memory Location "<<memo[f].loc<<" : "<<memo[f].info;
                            break;
                        }
                    }
                    if(fg)
                        cout<<"\n\n\t ERROR : OUT Of Bound Memory Location ";
                }
            }
            else if(deb=="Q"||deb=="QUIT"||deb=="E"||deb=="EXIT")
            {
                cout<<"\n\n\t EXITING DEBUGGER MODE";
                return 0;
            }

            else if(deb=="H"||deb=="HELP")
                help();

            else
                cout<<"\n\n\t ERROR : Not A Valid Debgger Option...";

        }while(1);
    }

    index=0;
    cout<<"\n\n\t Press Any Key To Continue..\n\n";
    getch();

    while(p[index].memloc!=END)
    {cout<<END<<" "<<p[index].memloc<<endl;
        compile();
        ++index;
    }


    PRINT_VALUES();

    return 0;

}
