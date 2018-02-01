void SET(char ch[])
{
    for(int i=0;i<6;i++)
    {
        if(!(isalnum(int(ch[i]))))
        {
            if(ch[i]==',')
                cout<<"\n\n\t NOTE : Don,t Use Comma In Set Command...";
            cout<<"\n\n\t ERROR : Invalid Memory Access";
            return;
        }
    }
    string mem="";
    for(int f=0;f<4;f++)
        mem+=ch[f];
    string data="";
    data+=ch[4];
    data+=ch[5];

    if(isdigit(int(ch[6]))||(ch[6]>='A'&&ch[6]<='F'))
    {
        cout<<"\n\n\t ERROR : Only 8-bit data is allowed"<<data;
        return;
    }
    memo[memoindex].loc=mem;
    memo[memoindex].info=data;
    memoindex++;
}
string CPY(char Reg)
{
        if(Reg=='A')
            return A;
        else if(Reg=='B')
            return B;
        else if(Reg=='C')
            return C;
        else if(Reg=='D')
            return D;
        else if(Reg=='E')
            return E;
        else if(Reg=='H')
            return H;
        else if(Reg=='L')
            return L;
        else if(Reg=='M')
            for(int i=0;i<memoindex;i++)
            {
                if(memo[i].loc==M||memo[i].loc==H+L)
                    return memo[i].info;
            }
        else
            cout<<"\n\n\t ERROR : Invalid RValue Error In Instruction At Memory Address "<<p[index].memloc<<endl;
}
void MOV(char ch[])
{
    if(ch[0]=='A')
        A=CPY(ch[2]);
    else if(ch[0]=='B')
        B=CPY(ch[2]);
    else if(ch[0]=='C')
        C=CPY(ch[2]);
    else if(ch[0]=='D')
        D=CPY(ch[2]);
    else if(ch[0]=='E')
        E=CPY(ch[2]);
    else if(ch[0]=='H')
    {
        H=CPY(ch[2]);
        M=H+L;
    }
    else if(ch[0]=='L')
    {
        L=CPY(ch[2]);
        M=H+L;
    }
    else if(ch[0]=='M')
    {
        M=CPY(ch[2]);
        H=M.string::substr(0,2);
        L=M.string::substr(2,4);
    }
    else
        cout<<"\n\n\t ERROR : Invalid LValue Error In Instruction At Memory Address "<<p[index].memloc<<endl;
}


void MVI(char ch[])
{
    string data;
    data+=ch[2];
    data+=ch[3];

    if(ch[0]=='A')
        A=data;
    else if(ch[0]=='B')
        B=data;
    else if(ch[0]=='C')
        C=data;
    else if(ch[0]=='D')
        D=data;
    else if(ch[0]=='E')
        E=data;
    else if(ch[0]=='H')
        H=data;
    else if(ch[0]=='L')
        L=data;
    else if(ch[0]=='M')
        {
            for(int i=0;i<memoindex;i++)
            {
                if(memo[i].loc==M)
                {
                    M="";
                    M=M+data;
                    memo[i].info=M;
                    M=memo[i].loc;
                    return ;
                }
            }
            memo[memoindex].loc=M;
            M=M+data;
            memo[memoindex].info=M;
            M=memo[memoindex].loc;
            memoindex++;
        }
    else
        cout<<"\n\n\t ERROR : Invalid LValue Error In Instruction At Memory Address "<<p[index].memloc<<endl;
}

void LXI(char ch[])
{
    string data1,data2;
    if(ch[1]==',')
    {
        data1+=ch[2];
        data1+=ch[3];
        data2+=ch[4];
        data2+=ch[5];
    }
    else
    {   data1+=ch[1];
        data1+=ch[2];
        data2+=ch[3];
        data2+=ch[4];
    }

    if(ch[0]=='H'||ch[0]=='M')
    {
        H=data1;
        L=data2;
        M=H+L;
    }
    else if(ch[0]=='B')
    {
        B=data1;
        C=data2;
    }
    else if(ch[0]=='D')
    {
        D=data1;
        E=data2;
    }
    else
        cout<<"\n\n\t ERROR : Invalid LValue Error In Instruction At Memory Address "<<p[index].memloc<<endl;
}

void LDA(char ch[])
{
    string CH;
    CH+=ch[0];
    CH+=ch[1];
    CH+=ch[2];
    CH+=ch[3];

    for(int i=0;i<memoindex;i++)
    {
        if(memo[i].loc==CH)
        {
            A = memo[i].info;
            return ;
        }
    }
        cout<<"\n\n\t ERROR : Invalid RValue Error In Instruction At Memory Address "<<p[index].memloc<<endl;
}

void STA(char ch[])
{
    string TEST;
    TEST+=ch[0];
    TEST+=ch[1];
    TEST+=ch[2];
    TEST+=ch[3];

    for(int i=0;i<memoindex;i++)
    {
        if(memo[i].loc==TEST)
        {
            memo[i].info=A;
            return ;
        }
    }
    if(TEST<start||TEST>END)
    {
        memo[memoindex].loc=TEST;
        memo[memoindex].info=A;
        memoindex++;
    }
    else
        cout<<"\n\n\t ERROR : Invalid RValue Error In Instruction At Memory Address "<<p[index].memloc<<endl;
}

void LHLD(char ch[])
{
    int flag = 0;
    string TEST,TEST1;
    TEST+=ch[0];
    TEST+=ch[1];
    TEST+=ch[2];
    TEST+=ch[3];
    TEST1=TEST;
    TEST1[3]+=1;
    if(TEST>=start&&TEST<=END)
    {
        cout<<"\n\n\t ERROR : Rvalue Is Under Program Scope...Contains instruction";
        return ;
    }
    for(int i=0;i<memoindex;i++)
    {
        if(memo[i].loc==TEST)
            flag++;
        else if(memo[i].loc==TEST1)
            flag++;
    }

    if(flag>=2)
    {
        for(int i=0;i<memoindex;i++)
        {
            if(memo[i].loc==TEST)
                L=memo[i].info;
            else if(memo[i].loc==TEST1)
                H=memo[i].info;
        }
        return;

        M = H+L;

    }
    else if(flag==1)
    {
        cout<<"\n\n\t ERROR : Invalid RValue Error In Instruction At Memory Address "<<p[index].memloc;
        cout<<endl<<"\n\n\t No Value Located At Memory Address "<<TEST;
    }
    else if(flag==0)
    {
        cout<<"\n\n\t ERROR : Invalid RValue Error In Instruction At Memory Address "<<p[index].memloc;
        cout<<endl<<"\n\n\t No Value Located At Memory Address "<<TEST;
        cout<<endl<<"\n\n\t No Value Located At Memory Address "<<TEST;
    }
}

void SHLD(char ch[])
{
    int flag = 0;
    string TEST,TEST1;
    TEST+=ch[0];
    TEST+=ch[1];
    TEST+=ch[2];
    TEST+=ch[3];

    TEST1=TEST;
    TEST[3]+=1;
    if(TEST>=start&&TEST<=END)
    {
        cout<<"\n\n\t ERROR : Rvalue Is Under Program Scope hence Contains Instruction";
        return ;
    }
    for(int i=0;i<memoindex;i++)
    {
        if(memo[i].loc==TEST)
            flag++;
        else if(memo[i].loc==TEST1)
            flag++;
    }

    if(flag>=2)
    {
        for(int i=0;i<memoindex;i++)
        {
            if(memo[i].loc==TEST)
                L=memo[i].info;
            else if(memo[i].loc==TEST1)
                H=memo[i].info;
        }
        return;

        M = H+L;

    }
    else if(flag==1)
    {
        cout<<"\n\n\t ERROR : Invalid RValue Error In Instruction At Memory Address "<<p[index].memloc;
        cout<<endl<<"\n\n\t No Value Located At Memory Address "<<TEST1;
    }
    else if(flag==0)
    {
        cout<<"\n\n\t ERROR : Invalid RValue Error In Instruction At Memory Address "<<p[index].memloc;
        cout<<endl<<"\n\n\t No Value Located At Memory Address "<<TEST;
        cout<<endl<<"\n\n\t No Value Located At Memory Address "<<TEST1;
    }
}

void STAX(char ch[])
{
    if(ch[0]=='B')
    {
        if(B=="")
        {
            cout<<"\n\n\t ERROR : Invalid RValue Error In Instruction At Memory Address "<<p[index].memloc;
            cout<<"\n\n\t No Value Located At Memory Address "<<B<<endl;
            return ;
        }
        if(C=="")
        {
            cout<<"\n\n\t ERROR : Invalid RValue Error In Instruction At Memory Address "<<p[index].memloc;
            cout<<"\n\n\t No Value Located At Memory Address "<<C<<endl;
            return ;
        }
        memo[memoindex].info=A;
        memo[memoindex].loc=B+C;
    }
    else if(ch[0]=='D')
    {
        if(D=="")
        {
            cout<<"\n\n\t ERROR : Invalid RValue Error In Instruction At Memory Address "<<p[index].memloc;
            cout<<"\n\n\t No Value Located At Memory Address "<<B<<endl;
            return ;
        }
        if(E=="")
        {
            cout<<"\n\n\t ERROR : Invalid RValue Error In Instruction At Memory Address "<<p[index].memloc;
            cout<<"\n\n\t No Value Located At Memory Address "<<E<<endl;
            return ;
        }
        memo[memoindex].info=A;
        memo[memoindex].loc=D+E;
    }
    else if(ch[0]=='H')
    {
        if(H=="")
        {
            cout<<"\n\n\t ERROR : Invalid RValue Error In Instruction At Memory Address "<<p[index].memloc;
            cout<<"\n\n\t No Value Located At Memory Address "<<H;
            return ;
        }
        if(L=="")
        {
            cout<<"\n\n\t ERROR : Invalid RValue Error In Instruction At Memory Address "<<p[index].memloc;
            cout<<"\n\n\t No Value Located At Memory Address "<<L<<endl;
            return ;
        }
        memo[memoindex].info=A;
        M=memo[memoindex].loc=H+L;
    }
    else
        cout<<"\n\n\t ERROR : Invalid RValue Error In Instruction At Memory Address "<<p[index].memloc<<endl;
}

void XCHG(char ch[])
{
    string temp;

    temp=H;
    H=D;
    D=temp;

    temp=L;
    L=E;
    E=temp;
}
