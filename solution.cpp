
#include "solution.h"

const int size = 8;

int board_buline[nmax][nmax] = { 0 };
int board_zone[nmax][nmax] = { 0 };

int coord[16][2], V[9]={0}, nrbuline;
int direction_i[4][4] = { -1,0,1,0,0,1,0,-1,1,0,-1,0,0,-1,0,1 }, direction_j[4][4] = { 0,1,0,-1,1,0,-1,0,0,-1,0,1,-1,0,1,0 };

bool gasit( int a, int b, int i ){ //asigura ca coord din matrice sunt distincte
     for(int k=0;k<i;k++)
         if(a==coord[k][0]&&b==coord[k][1])
            return true;
    return false;
}
void generate_coord() {
    int a, b;
   // srand(time(0));
    for(int i=0;i<size;i++)
        {srand(time(0));
               a=rand()% size;
            b=rand()% size;
            while(gasit(a,b,i)==true)
                {a= rand()% size; // coord bulina (a[0][j],a[1][j])
                 b=rand()% size;
                }

                //cout << "A  >" << a << endl;
                //cout << "B  >" << b << endl;
            coord[i][0]=a;
            coord[i][1]=b;
        }
}
void generate_board_buline(){
 int nr_bulina=-1;
 memset(board_buline,0,(nmax*nmax)*sizeof(int));
 for(int i=0;i<size;i++)
 {   board_buline[coord[i][0]][coord[i][1]]=nr_bulina;
     nr_bulina--;
 }
 }

void create_board_zone(){

    board_zone[nmax][nmax] = { 0 };
    for (int i = 0; i <size; i++)
        for (int j = 0; j < size; j++)
            board_zone[i][j] = board_buline[i][j];
}

void fill(int i, int j, int area_number, int& area, int pstart){

    for (int k = 0; k <3; k++) //vecinii adiacenti
    {
        if (area < size)
        {
            int newi = i + direction_i[pstart][k]; //pstart=1= sus, 2=dr, 3=jos, 4=stg
            int newj = j + direction_j[pstart][k];
            if (newi < 0 || newj < 0 || newi ==size || newj > size || board_zone[newi][newj] != 0)
                continue;
            area++;
            board_zone[newi][newj] = area_number; //marchez ca am fost pe aici
            fill(newi, newj, area_number, area, pstart); //pt a vedea unde pot ajunge din noul patratel
        }

    }
}

void possible_solution(int pstart) {

        create_board_zone();
        for (int i = 0; i <size; i++)
            for (int j = 0; j <size; j++)
                if (board_zone[i][j] < 0)
                {
                    int  area = 1;
                    int area_number = (-1) * board_zone[i][j];
                    board_zone[i][j]=area_number;
                    fill(i, j, area_number, area, pstart);
                }
}
bool OK(){

    int sum_zone = 0;
    for (int i = 0; i <size; i++)
        for (int j = 0; j <size; j++)
            if (board_zone[i][j] == 0)
               return 0;
    return 1;
}
void afisare(int board[nmax][nmax])
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
            {
             if(board[i][j]>=0)
                std::cout<<' ';
             std::cout<<board[i][j]<<' ';
            }
        std::cout<<std::endl;

    }

    std::cout << std::endl;
}

void solution(int &found){

    for (int pstart = 0; pstart <= 3; pstart++)
    {
        possible_solution(pstart);
        if (OK() == 1)
        {   found = 1;
            afisare(board_zone);
        }
    }
}

void insert_buline(int nrbulina){
    int a, b, nrzona=1;
    //srand(time(NULL));
    while(nrzona<=size)
            {srand(time(0));
                a=rand()% size;
            b=rand()% size;
            while(board_buline[a][b]!=0||board_zone[a][b]!=nrzona)
                {a= rand()% size; // coord bulina (a[0][j],a[1][j])
                 b=rand()% size;
                }
            board_buline[a][b]=nrbulina;
            nrbulina--;
            nrzona++;
            }

}

void generare_grupa1()
{
     int found=0;
    while(found==0)
        {generate_coord(); //buline1
        generate_board_buline();
        solution(found);
        }
}
void generare_grupa2()
{
     int found=0;
    while(found==0)
        {generate_coord(); //buline1
        generate_board_buline();
        solution(found);
        }
     nrbuline=(-1)*size-1;//buline 2
    insert_buline(nrbuline);
}
void generare_grupa4()
{

     int found=0;
    while(found==0)
        {generate_coord(); //buline1
        generate_board_buline();
        solution(found);
        }
    nrbuline=(-1)*size-1;//buline 2
    insert_buline(nrbuline);
    nrbuline=(-2)*size-1; //buline 3
    insert_buline(nrbuline);
    nrbuline=(-3)*size-1;//buline 4
    insert_buline(nrbuline);
}

void generare_grupa(int nbul){
    int found=0;
    while(found==0)
        {generate_coord(); //buline1
        generate_board_buline();
        solution(found);
        }

    if(nbul == 2){
        nrbuline=(-1)*size-1;//buline 2
        insert_buline(nrbuline);
    }
    if(nbul==4){
            nrbuline=(-1)*size-1;//buline 2
        insert_buline(nrbuline);
        nrbuline=(-2)*size-1; //buline 3
    insert_buline(nrbuline);
    nrbuline=(-3)*size-1;//buline 4
    insert_buline(nrbuline);
    }


}




