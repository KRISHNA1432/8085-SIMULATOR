void CMP(char ch[])
{
    if(ch[0]=='A')
        ZF=1;

    else if(ch[0]=='B')
    {
        if(A<B)
            CF=1;
        else if(A==B)
            ZF=1;
        else if(A>B)
            CF=ZF=0;
    }
    else if(ch[0]=='C')
    {
        if(A<C)
            CF=1;
        else if(A==C)
            ZF=1;
        else if(A>C)
            CF=ZF=0;
    }
    else if(ch[0]=='D')
    {
        if(A<D)
            CF=1;
        else if(A==D)
            ZF=1;
        else if(A>D)
            CF=ZF=0;
    }
    else if(ch[0]=='E')
    {
        if(A<E)
            CF=1;
        else if(A==E)
            ZF=1;
        else if(A>E)
            CF=ZF=0;
    }
    else if(ch[0]=='H')
    {
        if(A<H)
            CF=1;
        else if(A==H)
            ZF=1;
        else if(A>H)
            CF=ZF=0;
    }
    else if(ch[0]=='L')
    {
        if(A<L)
            CF=1;
        else if(A==L)
            ZF=1;
        else if(A>L)
            CF=ZF=0;
    }

    else if(ch[0]=='M')
        for(int i=0;i<memoindex;i++)
        {
            if(memo[i].loc==M||memo[i].loc==H+L)
            {
                if(A<memo[i].info)
                    CF=1;
                else if(A==memo[i].info)
                    ZF=1;
                else if(A>memo[i].info)
                    CF=ZF=0;
            }
        }
    else
        cout<<"\n\n\t Invalid RValue Error In Instruction At Memory Address "<<p[index].memloc<<endl;

}

void CMA()
{
    stringstream ss;
    ss << hex << A;
    unsigned n;
    ss >> n;
    bitset<8> b(n);

    b.flip();

    int temp = b.to_ulong() ;

    A = DtoH(temp);

}
