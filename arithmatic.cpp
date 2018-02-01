void ADD(char ch[])
{
    if(ch[0]=='A')
    {
        A=DtoH(abs(HtoD(A)+HtoD(A)));
        if(A>"FF")
        {
            cout<<"\n\n\t Out Of Bound Value"<<endl;
            A=DtoH(abs(HtoD(A)-HtoD(A)));
            return ;
        }
    }
    else if(ch[0]=='B')
    {
        A=DtoH(abs(HtoD(A)+HtoD(B)));
        if(A>"FF")
        {
            cout<<"\n\n\t Out Of Bound Value"<<endl;
            A=DtoH(abs(HtoD(A)-HtoD(B)));
            return ;
        }
    }
    else if(ch[0]=='C')
    {
        A=DtoH(abs(HtoD(A)+HtoD(C)));
        if(A>"FF")
        {
            cout<<"\n\n\t Out Of Bound Value"<<endl;
            A=DtoH(abs(HtoD(A)-HtoD(C)));
            return ;
        }
    }
    else if(ch[0]=='D')
    {
        A=DtoH(abs(HtoD(A)+HtoD(D)));
        if(A>"FF")
        {
            cout<<"\n\n\t Out Of Bound Value"<<endl;
            A=DtoH(abs(HtoD(A)-HtoD(D)));
            return ;
        }
    }
    else if(ch[0]=='E')
    {
        A=DtoH(abs(HtoD(A)+HtoD(E)));
        if(A>"FF")
        {
            cout<<"\n\n\t Out Of Bound Value"<<endl;
            A=DtoH(abs(HtoD(A)-HtoD(E)));
            return ;
        }
    }
    else if(ch[0]=='H')
    {
        A=DtoH(abs(HtoD(A)+HtoD(H)));
        if(A>"FF")
        {
            cout<<"\n\n\t Out Of Bound Value"<<endl;
            A=DtoH(abs(HtoD(A)-HtoD(E)));
            return ;
        }
    }
    else if(ch[0]=='L')
    {
        A=DtoH(abs(HtoD(A)+HtoD(L)));
        if(A>"FF")
        {
            cout<<"\n\n\t Out Of Bound Value"<<endl;
            A=DtoH(abs(HtoD(A)-HtoD(L)));
            return ;
        }
    }
    else if(ch[0]=='M')
        for(int i=0;i<memoindex;i++)
        {
            if(memo[i].loc==M||memo[i].loc==H+L)
            {
                A=DtoH(abs(HtoD(A)+HtoD(memo[i].info)));
                if(A>"FF")
                {
                    cout<<"\n\n\t Out Of Bound Value"<<endl;
                    A=DtoH(abs(HtoD(A)-HtoD(memo[i].info)));
                    return ;
                }
                break;
            }
        }
    else
        cout<<"\n\n\t Invalid LValue Error In Instruction At Memory Address "<<p[index].memloc<<endl;

    updateflag();
}

void ADI(char ch[])
{
    string TEST;
    TEST+=ch[0]+ch[1];
    if(!(isalnum(int(ch[0]))&&isalnum(int(ch[1]))))
    {
        A+=TEST;
        if(A>"FF")
            CF=1;
        else
            CF=0;
    }
    else
        cout<<"\n\n\t Invalid LValue Error In Instruction At Memory Address "<<p[index].memloc<<endl;

    updateflag();
}

void SUB(char ch[])
{
    if(ch[0]=='A')
    {
        A=DtoH(abs(HtoD(A)-HtoD(A)));
        if(A<B)
            CF=1;
        else
            CF=0;
        if(A=="00")
            ZF=1;
        else
            ZF=0;
    }
    else if(ch[0]=='B')
    {
        A=DtoH(abs(HtoD(A)-HtoD(B)));
        if(A<B)
            CF=1;
        else
            CF=0;

        if(B=="00")
            ZF=1;
        else
            ZF=0;
    }
    else if(ch[0]=='C')
    {
        A=DtoH(abs(HtoD(A)-HtoD(C)));
        if(A<C)
            CF=1;
        else
            CF=0;

        if(C=="00")
            ZF=1;
        else
            ZF=0;
    }
    else if(ch[0]=='D')
    {
        A=DtoH(abs(HtoD(A)-HtoD(D)));
        if(A<D)
            CF=1;
        else
            CF=0;

        if(D=="00")
            ZF=1;
        else
            ZF=0;
    }
    else if(ch[0]=='E')
    {
        A=DtoH(abs(HtoD(A)-HtoD(E)));
        if(A<E)
            CF=1;
        else
            CF=0;

        if(E=="00")
            ZF=1;
        else
            ZF=0;
    }
    else if(ch[0]=='H')
    {
        A=DtoH(abs(HtoD(A)-HtoD(H)));
        if(A<H)
            CF=1;
        else
            CF=0;
        if(H=="00")
            ZF=1;
        else
            ZF=0;
    }
    else if(ch[0]=='L')
    {
        A=DtoH(abs(HtoD(A)-HtoD(L)));
        if(A<L)
            CF=1;
        else
            CF=0;

        if(L=="00")
            ZF=1;
        else
            ZF=0;
    }
    else if(ch[0]=='M')
        for(int i=0;i<memoindex;i++)
        {
            if(memo[i].loc==M||memo[i].loc==H+L)
            {
                A=DtoH(abs(HtoD(A)-HtoD(memo[i].info)));
                if(A<memo[i].info)
                    CF=1;
                else
                    CF=0;
                if(A=="00")
                    ZF=1;
                else
                    ZF=0;
                break;
            }
        }
    else
        cout<<"\n\n\t Invalid LValue Error In Instruction At Memory Address "<<p[index].memloc<<endl;

    updateflag();
}

void SUI(char ch[])
{
    string TEST;
    TEST+=ch[0]+ch[1];
    if(!(isalnum(int(ch[0]))&&isalnum(int(ch[1]))))
    {
        if(A==TEST)
        {
            CF=0;
            ZF=1;
            A="00";
        }
        else if(A<TEST)
        {
            CF=1;
            ZF=0;
            A=DtoH(HtoD("FF")-(HtoD(TEST)-HtoD(A)));
        }
        else
        {
            CF=0;
            ZF=0;
            A=DtoH(HtoD(A)-HtoD(TEST));
        }

    }
    else
        cout<<"\n\n\t Invalid LValue Error In Instruction At Memory Address "<<p[index].memloc<<endl;

    updateflag();
}

void INR(char ch[])
{
    if(ch[0]=='A')
    {
        if(A=="FF")
        {
            A="00";
            CF=1;
            ZF=1;
        }
        else
        {
            A=DtoH(HtoD(A)+1);
            CF=0;
            ZF=0;
        }
    }
    else if(ch[0]=='B')
    {
       if(B=="FF")
        {
            B="00";
            CF=1;
            ZF=1;
        }
        else
        {
            B=DtoH(HtoD(B)+1);
            CF=0;
            ZF=0;
        }
    }
    else if(ch[0]=='C')
    {
        if(C=="FF")
        {
            C="00";
            CF=1;
            ZF=1;
        }
        else
        {
            C=DtoH(HtoD(C)+1);
            CF=0;
            ZF=0;
        }
    }
    else if(ch[0]=='D')
    {
        if(D=="FF")
        {
            D="00";
            CF=1;
            ZF=1;
        }
        else
        {
            D=DtoH(HtoD(D)+1);
            CF=0;
            ZF=0;
        }
    }
    else if(ch[0]=='E')
    {
        if(E=="FF")
        {
            E="00";
            CF=1;
            ZF=1;
        }
        else
        {
            E=DtoH(HtoD(E)+1);
            CF=0;
            ZF=0;
        }
    }
    else if(ch[0]=='H')
    {
        if(H=="FF")
        {
            H="00";
            CF=1;
            ZF=1;
        }
        else
        {
            H=DtoH(HtoD(H)+1);
            CF=0;
            ZF=0;
        }
        M=H+L;
    }
    else if(ch[0]=='L')
    {
        if(L=="FF")
        {
            L="00";
            CF=1;
            ZF=1;
        }
        else
        {
            L=DtoH(HtoD(L)+1);
            CF=0;
            ZF=0;
        }
        M=H+L;
    }
    else if(ch[0]=='M')
        for(int i=0;i<memoindex;i++)
        {
            if(memo[i].loc==M||memo[i].loc==H+L)
            {
                if(memo[i].info=="FF")
                {
                    memo[i].info="00";
                    CF=1;
                    ZF=1;
                }
                else
                {
                    memo[i].info=DtoH(HtoD(A)+1);
                    CF=0;
                    ZF=0;
                }

                M = H + L;
                break;
            }
        }
    else
        cout<<"\n\n\t Invalid LValue Error In Instruction At Memory Address "<<p[index].memloc<<endl;

    updateflag();
}

void DCR(char ch[])
{
    if(ch[0]=='A')
    {
        if(A=="00")
        {
            A="FF";
            CF=1;
        }
        else
        {
            A=DtoH(HtoD(A)-1);
            CF=0;
        }

        if(A=="00")
            ZF=1;
        else
            ZF=0;
    }
    else if(ch[0]=='B')
    {
       if(B=="00")
        {
            B="FF";
            CF=1;
        }
        else
        {
            B=DtoH(HtoD(B)-1);
            CF=0;
        }

        if(B=="00")
            ZF=1;
        else
            ZF=0;
    }
    else if(ch[0]=='C')
    {
        if(C=="00")
        {
            C="FF";
            CF=1;
        }
        else
        {
            C=DtoH(HtoD(C)-1);
            CF=0;
        }

        if(C=="00")
            ZF=1;
        else
            ZF=0;
    }
    else if(ch[0]=='D')
    {
        if(D=="00")
        {
            D="FF";
            CF=1;
        }
        else
        {
            D=DtoH(HtoD(D)-1);
            CF=0;
        }

        if(D=="00")
            ZF=1;
        else
            ZF=0;
    }
    else if(ch[0]=='E')
    {
        if(E=="00")
        {
            E="FF";
            CF=1;
        }
        else
        {
            E=DtoH(HtoD(E)-1);
            CF=0;
        }

        if(E=="00")
            ZF=1;
        else
            ZF=0;
    }
    else if(ch[0]=='H')
    {
        if(H=="00")
        {
            H="FF";
            CF=1;
        }
        else
        {
            H=DtoH(HtoD(H)-1);
            CF=0;
        }

        if(H=="00")
            ZF=1;
        else
            ZF=0;
        M=H+L;
    }
    else if(ch[0]=='L')
    {
        if(L=="00")
        {
            L="FF";
            CF=1;
        }
        else
        {
            L=DtoH(HtoD(L)-1);
            CF=0;
        }

        if(L=="00")
            ZF=1;
        else
            ZF=0;
        M=H+L;
    }
    else if(ch[0]=='M')
        for(int i=0;i<memoindex;i++)
        {
            if(memo[i].loc==M||memo[i].loc==H+L)
            {
                if(memo[i].info=="00")
                {
                    memo[i].info="FF";
                    CF=1;
                }
                else
                {
                    memo[i].info=DtoH(HtoD(A)-1);
                    CF=0;
                }

                if(memo[i].info=="00")
                    ZF=1;
                else
                    ZF=0;

                M = H + L;
                break;
            }
        }
    else
        cout<<"\n\n\t Invalid LValue Error In Instruction At Memory Address "<<p[index].memloc<<endl;

    updateflag();
}

void INX(char ch[])
{
    if(ch[0]=='B')
    {
        if(C=="FF")
        {
            C=="00";
            B=DtoH(HtoD(B)+1);
        }
        else
            C=DtoH(HtoD(C)+1);
        if(B>"FF")
            CF=1;
        else
            CF=0;
    }
    else if(ch[0]=='D')
    {
        if(E=="FF")
        {
            E=="00";
            D=DtoH(HtoD(D)+1);
        }
        else
            E=DtoH(HtoD(E)+1);
        if(D>"FF")
            CF=1;
        else
            CF=0;
    }
    else if(ch[0]=='H'||ch[0]=='M')
    {
        if(L=="FF")
        {
            L=="00";
            H=DtoH(HtoD(H)+1);
        }
        else
            L=DtoH(HtoD(L)+1);
        if(H>"FF")
            CF=1;
        else
            CF=0;
    }
    else
        cout<<"\n\n\t Invalid LValue Error In Instruction At Memory Address "<<p[index].memloc<<endl;

    updateflag();
}
void DCX(char ch[])
{
    if(ch[0]=='B')
    {
        if(C=="00")
        {
            C=="FF";
            B=DtoH(HtoD(B)-1);
        }
        else
            C=DtoH(HtoD(C)-1);
        if(B<"00")
            CF=1;
        else
            CF=0;
    }
    else if(ch[0]=='D')
    {
        if(E=="00")
        {
            E=="FF";
            D=DtoH(HtoD(D)-1);
        }
        else
            E=DtoH(HtoD(E)-1);
        if(D<"00")
            CF=1;
        else
            CF=0;
    }
    else if(ch[0]=='H'||ch[0]=='M')
    {
        if(L=="00")
        {
            L=="FF";
            H=DtoH(HtoD(H)-1);
        }
        else
            L=DtoH(HtoD(L)-1);
        if(D>"FF")
            CF=1;
        else
            CF=0;
    }
    else
        cout<<"\n\n\t Invalid LValue Error In Instruction At Memory Address "<<p[index].memloc<<endl;

    updateflag();
}

void DAD(char ch[])
{
    if(ch[0]=='H')
    {
       L=DtoH(2*HtoD(L));
       H=DtoH(2*HtoD(H));
    }
    else if(ch[0]=='B')
    {
        L=DtoH(HtoD(L)+HtoD(C));
        H=DtoH(HtoD(H)+HtoD(B));
    }
    else if(ch[0]=='D')
    {
        L=DtoH(HtoD(L)+HtoD(E));
        H=DtoH(HtoD(H)+HtoD(D));
    }
    else
        cout<<"\n\n\t Invalid LValue Error In Instruction At Memory Address "<<p[index].memloc<<endl;

    updateflag();
}
