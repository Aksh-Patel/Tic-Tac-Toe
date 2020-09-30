#include <iostream>

using namespace std;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';
bool draw=true;
bool end1=true;
void displayboard()
{
    cout<<"\t\t\t\t\t"<<board[0][0]<<"  |  "<<board[0][1]<<"\t  | "<<board[0][2]<<"\t\t\t\t\n";
    cout<<"\t\t\t\t\t   |  \t  |  \t\t\t\t\n";
    cout<<"\t\t\t\t    --------------------\n";
    cout<<"\t\t\t\t\t"<<board[1][0]<<"  |  "<<board[1][1]<<"\t  |  "<<board[1][2]<<"\t\t\t\t\n";
    cout<<"\t\t\t\t\t   |  \t  |  \t\t\t\t\n";
    cout<<"\t\t\t\t    --------------------\n";
    cout<<"\t\t\t\t\t"<<board[2][0]<<"  |  "<<board[2][1]<<"\t  |  "<<board[2][2]<<"\t\t\t\t\n";
    cout<<"\t\t\t\t\t   |  \t  |  \t\t\t\t\n";

}
void playerturn()
{
    if(turn=='X')
    {
        cout<<"player 1 : turn :\n";
    }
    else if(turn=='0')
    {
        cout<<"player 2 : turn :\n";
    }
    int choice;
    cin>>choice;
    int row,column;
    switch(choice)
    {
        case 1:row=0; column=0;break;
        case 2:row=0; column=1;break;
        case 3:row=0; column=2;break;
        case 4:row=1; column=0;break;
        case 5:row=1; column=1;break;
        case 6:row=1; column=2;break;
        case 7:row=2; column=0;break;
        case 8:row=2; column=1;break;
        case 9:row=2; column=2;break;
        default: cout<<"Invalid move";break;
    }
    if(turn=='X' && board[row][column]!='X' && board[row][column]!='0')
    {
        board[row][column]='X';
        turn='0';
    }
    else if(turn=='0' && board[row][column]!='X' && board[row][column]!='0')
    {
        board[row][column]='0';
        turn='X';
    }
    else
    {
      cout<<"enter a valid character\n";

    }


}
void gameover()
{   end1=false;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
          if(board[i][j]!='X' && board[i][j]!='0')
            {
                end1=true;
                break;
            }
        }
    }
    if(end1==false)
    {
        cout<<"\t\t\t\t5\t\t\tmatch draws!!!!!!!!!!!!!!!!!!\n";
        exit(0);
    }

    for(int j=0;j<3;j++)
   {

            if(board[0][j]==board[1][j] && board[2][j]==board[0][j])
            {   if( board[0][j]=='X')
                {
                    cout<<"\t\t\t\t\t\tplayer 1 is winner!!!!!!!!!!!!!!!!!\t\n";
                }
                else
                {
                    cout<<"\t\t\t\t\t\tplayer 2 is winner!!!!!!!!!!!!!!!!!!\t\n";
                }
                draw=false;
            }
            else if(board[j][0]==board[j][1] && board[j][2]==board[j][0])
            {
                 if( board[j][0]=='X')
                {
                    cout<<"\t\t\t\t\t\tplayer 1 is winner!!!!!!!!!!!!!!!!!\t\n";
                }
                else
                {
                    cout<<"\t\t\t\t\t\tplayer 2 is winner!!!!!!!!!!!!!!!!!!\t\n";
                }
                draw=false;
            }



    }
   if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
   {
       if(board[0][0]=='X')
        {
            cout<<"\t\t\t\t\t\t\tplayer 1 is winner!!!!\t\t\t\t\n";
        }
        else
        {
            cout<<"\t\t\t\t\t\t\tplayer 2 is winner!!!!\t\t\t\t\n";
        }
        draw=false;
   }


}
int main()
{
    cout<<"\t\t\t\t\tTIC TAC TOE (sun chokdi)\t\t\t\t\t\n";
    cout<<"\t\t\t\tPlayer 1 : X\t\tPlayer 2 : 0\n\n\n\n";
    displayboard();
    while(draw==true && end1==true)
    {

        playerturn();
        gameover();
        displayboard();
    }
    return 0;
}
