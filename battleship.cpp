#include <iostream>
#include <string>
using namespace std;

void ship_move(int a[10][10] , int mkan[5][2]);
void ship_location(int a[10][10] , int mkan[5][2]);
void scan(int a[10][10]);
void repair(int a[10][10]);
void game_page(int a[10][10]);

int main()
{
    cout << "< WELCOME TO THE GAME BATTLESHIP *_* > \n\n" << " Please enter your name\n";              //start of the game
    string p1, p2;
    cout << " player1 ---> ";
    cin >> p1;
    cout << " player2 ---> ";
    cin >> p2;

    int a1[10][10] = {0};                       
    int a2[10][10] = {0};

    
    int mkan1[5][2] = {0};
    int mkan2[5][2] = {0};
    
    ship_location(a1 , mkan1);          //primary location of ships
    ship_location(a2 , mkan2);
    

    int sum1 = 0;
    int sum2 = 0;

    int n_repair1 = 0;
    int n_repair2 = 0;

    while( sum1 != 17 && sum2 != 17 )               //the main body
    {

        cout << "\n\n\n" << p1;                                                 // p1 turn
        game_page(a1);

        cout << "\nWhat do you want to do??\n\n";
        cout << "1- shooting \n" << "2- Area scan \n" << "3- ship repair \n";
        cout << "Entern the desired option ---> ";
        int op = 0;
        cin >> op;

        for(int i2 = 0 ; n_repair1 > 3 && op == 2 ; i2++){
            cout << "finished number of repairs;\n";
            cout << "Entern the desired option again --->> ";
            cin >> op;
        }
        for(int i2 = 0 ; op < 1 || op > 3 ; i2++){
            cout << "Entern the desired option again --->> ";
            cin >> op;
        }

        if(op == 1)
        {
            int n = 0, m = 0;
            cout << "Shoot ---> ";
            cin >> n >> m;

            if( a2[n - 1][m - 1] == 1 )
            {
                a2[n - 1][m - 1] = -1;
                cout << "++ Your shot was cottect (:";
            } else {
                if( a2[n - 1][m - 1] == -1 )
                {
                    cout << "^^ You shot here before /:";
                } else {
                    if( a2[n - 1][m - 1] == 2 )
                    {
                        a2[n - 1][m - 1] = 0;                                      
                        if( a1[n - 1][m - 1] == 1 )
                        {
                            a1[n - 1][m - 1] = -1;
                            cout << "** You shot the mine ]:\n" << "and you are not safe ]: ";
                        } else {
                            cout << "** You shot the mine ]:\n" << "but you are safe (;";

                        }
                    } else {
                        cout << "-- Your shot was wrong ):";
                    }
                }
            }
        }

        if(op == 2)
        {
            scan(a2);
        }

        if(op == 3)
        {
            if(sum2 != 0 ){
                repair(a1);
                n_repair1++;
            } else {
                cout << "you don't have a Hit point );";
            }
        }


        sum1 = 0;
        for(int i = 0 ; i < 10 ; i++){                                  
            for(int j = 0 ; j < 10 ;j++){
                if( a2[i][j] == -1 ){
                    sum1++;
                }
            }
        }


        cout << "\n\n\n" << p2;                                                       // p2 turn
        game_page(a2);
        
        cout << "What do you want to do??\n\n";
        cout << "1- shooting \n" << "2- Area scan \n" << "3- ship repair \n";
        cout << "Entern the desired option ---> ";
        op = 0;
        cin >> op;

        for(int i2 = 0 ; n_repair2 > 3 && op == 2 ; i2++){
            cout << "finished number of repairs;\n";
            cout << "Entern the desired option again --->> ";
            cin >> op;
        }
        for(int i2 = 0 ; op < 1 || op > 3 ; i2++){
            cout << "Entern the desired option again --->> ";
            cin >> op;
        }

        if(op == 1)
        {
            int n = 0, m = 0;
            cout << "Shoot ---> ";
            cin >> n >> m;
            
            if( a1[n - 1][m - 1] == 1 )
            {
                a1[n - 1][m - 1] = -1;
                cout << "++ Your shot was cottect (:";
            } else {
                if( a1[n - 1][m - 1] == -1 )
                {
                    cout << "^^ You shot here before /:";
                } else {
                    if( a1[n - 1][m - 1] == 2 )
                    {
                        a1[n - 1][m - 1] = 0;                                           
                        if( a2[n - 1][m - 1] == 1 )
                        {
                            a2[n - 1][m - 1] = -1;
                            cout << "** You shot the mine ]:\n" << "and you are not safe ]: ";
                        } else {
                            cout << "** You shot the mine ]:\n" << "but you are safe (;";

                        }
                    } else {
                        cout << "-- Your shot was wrong ):";
                    }
                }
            }
        }

        if(op == 2)
        {
            scan(a1);
        }

        if(op == 3)
        {
            if( sum1 != 0 ){  
                repair(a2);
                n_repair2++;
            } else {
                cout << "you don't have a Hit point );";
            }
        }


        ship_move(a1 , mkan1);                                               //ship movememt
        ship_move(a2 , mkan2);


        sum1 = 0;
        sum2 = 0;

        for(int i = 0 ; i < 10 ; i++){                                   //end of the game
            for(int j = 0 ; j < 10 ;j++){
                if( a2[i][j] == -1 ){
                    sum1++;
                }
                if( a1[i][j] == -1 ){
                    sum2++;
                }
            }
        }


    }

    cout << "<<<<  THE GAME IS OVER (;   >>>>\n\n" << "THE WINER IS ------>>>  .";     //the end of the game
    if(sum1 == 17){
        cout << p1 << ".  ^o^";
    } else {
        cout << p2 << ".  ^o^";
    }

    cout << "\n\n\nTHE END.";

    return 0;
}

void ship_move(int a[10][10] , int mkan[5][2])                         //ship movement
{
    for(int i = 5 ; i > 0 ; i--)
    {

        int satr = mkan[i - 1][0];
        int soton = mkan[i - 1][1];
       
        int i3 = i;
        if(i == 1){
            i3 = 3;
        }

        int sib = 4;
        for(int j = 0 ; j < i3 ; j++){
            if( a[satr][soton + j] == 1 ){
                sib = 0;
            }
        }
        
        
        int jahat = 1 +  rand() % 4;
        
        int b1 = 0;
        int b2 = 0;
        int b3 = 0;
        int b4 = 0;
        
        while(sib < 3)
        {
            if(jahat == 1)          //up
            {
                if(satr == 0){
                    b1 = 1;
                    if( b2 == 0){
                        jahat = 2;
                    }
                    if( b2 == 1){
                        jahat = 3;
                    }
                }
                for(int j = 0 ; j < i3 && b1 == 0 ; j++){
                    if( a[satr - 1][soton + j] != 0 ){
                        b1 = 1;
                        if( b2 == 0){
                            jahat = 2;
                        }
                        if( b2 == 1){
                            jahat = 3;
                        }
                    }
                }
                if(b1 == 0){
                    for(int j = 0 ; j < i3 ; j++){
                        a[satr - 1][soton + j] = a[satr][soton + j];
                        a[satr][soton + j] = 0;
                    }
                    sib = 4;
                    satr--;
                }
            }

            if(jahat == 2)      //down
            {
                if(satr == 9){
                    b2 = 1;
                    if( b1 == 0 ){
                        jahat = 1;      
                    }
                    if(b1 == 1){
                        if( b3 == 0 ){
                            jahat = 3;
                        }
                        if( b3 == 1 ){
                            sib = 4;
                        }
                    }
                }
                for(int j = 0 ; j < i3 && b2 == 0; j++){
                    if( a[satr + 1][soton + j] != 0 ){
                        b2 = 1;
                        if( b1 == 0 ){
                            jahat = 1;      
                        }
                        if( b1 == 1 ){
                            if( b3 == 0 ){
                                jahat = 3;
                            }
                            if( b3 == 1 ){
                                sib = 4;
                            }
                        }
                    }
                }
                if(b2 == 0){
                    for(int j = 0 ; j < i3 ; j++){
                        a[satr + 1][soton + j] = a[satr][soton + j];
                        a[satr][soton + j] = 0;
                    }
                    sib = 4;
                    satr++;
                }

            }

            if(jahat == 3)      //right
            {
                if( a[satr][soton + i3] != 0 || soton + i3 == 10){
                    b3 = 1;
                    if( b4 == 0 ){
                        jahat = 4;
                    }
                    if( b4 == 1 ){
                        jahat = 1;
                    }
                }
                if(b3 == 0){
                    for(int j = 0 ; j < i3 ; j++){
                        a[satr][soton + i - j] = a[satr][soton + (i - 1) - j];
                        a[satr][soton + (i - 1) - j] = 0;
                    }
                    sib = 4;
                    soton++;
                }
            }

            if(jahat == 4)      //left
            {
                if( a[satr][soton - 1] != 0 || soton == 0 ){
                    b4 = 1;
                    if( b3 == 0 ){
                        jahat = 3;
                    }
                    if( b3 == 1 ){
                        if( b1 == 0 ){
                            jahat = 1;
                        }
                        if( b1 == 1 ){
                            sib = 4;
                        }
                    }
                }
                if(b4 == 0){
                    for(int j = 0 ; j < i3 ; j++){
                        a[satr][soton + (j - 1)] = a[satr][soton + j];
                        a[satr][soton + j] = 0;
                    }
                    sib = 4;
                    soton--;
                }
            
            }
            sib++;
        
        }

        mkan[i - 1][0] = satr;
        mkan[i - 1][1] = soton;
    }
}

void ship_location(int a[10][10] , int mkan[5][2])                     //location of ships
{
    int satr = 0;  
    int soton = 0;

    int b = 0;

    for(int i = 5 ; i > 1 ; i--)
    {
        satr = rand() % 10;
        soton = rand() % (11 - i);    

        int k1 = 0;
        int k2 = 0;
        
        int corect = 1;

        for(int j = 0 ; j < i ; j++)
        {
            if(a[satr][soton + j] == 0 && (soton + j) < 10)
            {
                a[satr][soton + j] = 1;
                k1++;
            } else {
                if(a[satr][soton - (k2 + 1)] == 0 && (soton - (k2 + 1)) > -1)
                {
                    a[satr][soton - (k2 + 1)] = 1;
                    k2++;
                } else {
                    for(int i2 = 0 ; k1 != 0 ; i2++){
                        a[satr][soton  + (k1 - 1)] = 0;
                        k1--;
                    }
                    for(int i2 = 0 ; k2 != 0 ; i2++){
                        a[satr][soton - (k2 + 1)] = 0;
                        k2--;
                    }
                    i++;
                    break;
                    corect = 0;
                }
            }
        }

        if(corect == 1){
            mkan[i - 1][0] = satr;
            mkan[i - 1][1] = soton;

            if( i == 3 && b == 0){
                i++;
                b = 1;
                mkan[0][0] = satr;
                mkan[0][1] = soton;
            }
        }
    }


    for(int i = 0 ; i < 3 ; i++)
    {
        satr = rand() % 10;
        soton = rand() % 10;

        if( a[satr][soton] == 0 ){
            a[satr][soton] = 2;
        } else {
            i--;
        }
    }

}

void scan(int a[10][10])                                               //scan area
{
    cout << "scanned area locatin :\n" << "location of the up left ---> "; 
    int up = 0 , lf = 0;
    cin >> up >> lf;

    
    for(int i2 = 0 ; up < 1 || up > 7 || lf < 1 || lf > 7 ; i2++){
        cout << "enter location of the up left again --->> ";
        cin >> up >> lf;
    }

    cout << "location of the down right is--> ";
    cout << lf + 3<< ' ' << up + 3;

    int b = 0;
    for(int i = (up - 1) ; i < (up + 3) && b != 1 ; i++){
        for(int j = (lf - 1) ; j < (lf + 3) ; j++){
            if( a[i][j] == 1 ){
                b = 1;
                break;
            }
        }
    }

    if( b == 1 ){
        cout << "\n\n++ Ship Detected (;";
    } else {
        cout << "\n\n-- No Ship in Area ):";
    }

}

void repair(int a[10][10])                                             //ship repair 
{
    int r1 = 0 , r2 = 0;
    cout << "repair location ---> ";
    cin >> r1 >> r2;

    for(int i2 = 0 ; r1 < 1 || r1 > 10 || r2 < 1 || r2 > 10 ; i2++){
        cout << "entar repair location again --->> ";
        cin >> r1 >> r2;
    }

    for(int i2 = 0 ; a[r1 - 1][r2 - 1] != -1 ; i2++){
        cout << "entar repair location again --->> ";
        cin >> r1 >> r2;
    }

    if( a[r1 - 1][r2 - 1] == -1 ){
        a[r1 - 1][r2 - 1] = 1;
        cout << "$ Your ship has been repaired (;";
    }
}

void game_page(int a[10][10])                                          //create a page
{
    
    cout << "\n ";                      // first line
    for(int i = 1 ; i < 11 ; i++){
        cout << "   " << i;
    }
    cout << "\n  ";
    for(int i = 0 ; i < 10 ; i++){
        cout << " ---";
    }

    for(int i = 1 ; i < 10 ; i++)        //main body
    {         
        cout << "\n" << i << " |";
        for(int j = 0 ; j < 10 ; j++)
        {
            if(a[i - 1][j] == 1){
                cout << " * |";
            } else {
                if(a[i - 1][j] == -1 ){
                    cout << " # |";
                } else {
                    if(a[i - 1][j] == 2){
                        cout << " @ |";
                    } else {
                        cout << "   |";
                    }
                }
            }
        }
        cout << "\n  ";
        for(int i2 = 0 ; i2 < 10 ; i2++){
            cout << " ---";
        }
    }

    cout << "\n" << 10 << "|";        //for 10
    for(int i = 0 ; i < 10 ; i++)
    {
        if(a[9][i] == 1 ){
            cout << " * |";
        } else {
            if(a[9][i] == -1 ){
                cout << " # |";
            } else {
                if(a[9][i] == 2){
                    cout << " @ |";
                } else {
                    cout << "   |";
                }
            }
        }
    }
    cout << "\n  ";
    for(int i = 0 ; i < 10 ; i++){
        cout << " ---";
    }
    cout << "\n";
}
