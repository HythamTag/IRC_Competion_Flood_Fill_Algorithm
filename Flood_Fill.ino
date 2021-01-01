
void path(int OneZeros[][6],int raw,int col,int start[],int finish[],int LastNavigation){

    int pf[9][6]={};
    raw-=1;
    col-=1;



    int y,x;
    int points[2][1][100] = {};
    int C = 2;
    int v2 = 0;
    int lastCount = -1;
    int Count = 0;
    int counter=0;

    y=finish[0];
    x=finish[1];

    pf[y][x]=1;

    points[0][0][0]=y;
    points[1][0][0]=x;
Serial.println("///////////////////////////////////");   
 Serial.print("finish raw = ");
 Serial.print(finish[0]);
 Serial.print(" finish col = ");
 Serial.println(finish[1]);
 Serial.println("///////////////////////////////////");
 Serial.println("///////////////////////////////////");   
 Serial.print("start raw = ");
 Serial.print(start[0]);
 Serial.print(" start col = ");
 Serial.println(start[1]);
 Serial.println("///////////////////////////////////");
 Serial.println("///////////////////////////////////");
  Serial.println("The Ones and Zeros :");
for(int l=raw; l>=0; l--)
    {
        for(int k=0; k<=col ; k++)
        {


            Serial.print(OneZeros[l][k]);
            Serial.print("   ");
        }
        Serial.println("");
        
    }

     Serial.println("");


 Serial.println("///////////////////////////////////");
    while(lastCount != Count)
    {
    lastCount=Count;

        for(int i=v2; i<=Count; i++)
        {
            y = points[0][0][i];
            x = points[1][0][i];
  
            if (((y+1)>=0) &&((y+1)<= raw) && ((x)>=0) && ((x)<=col && OneZeros[y+1][x]==1 && pf[y+1][x] ==0))
            {
         counter++;
                pf[y+1][x] = (OneZeros[y+1][x])*C;
                points[0][0][counter] = (y+1);
                points[1][0][counter] = x;


            }

            if (((y-1)>=0) &&((y-1)<= raw) && ((x)>=0) && ((x)<=col && OneZeros[y-1][x]==1) &&(pf[y-1][x]==0))
            {
        counter++;
                pf[y-1][x] = OneZeros[y-1][x]*C;
                points[0][0][counter] = (y-1);
                points[1][0][counter] = (x);


            }

            if (((y)>=0) && ((y)<= raw) && ((x+1)>=0) && ((x+1)<=col) && (OneZeros[y][x+1]==1) && (pf[y][x+1]==0))
            {
        counter++;
                pf[y][x+1] = OneZeros[y][x+1]*C;
                points[0][0][counter] = (y);
                points[1][0][counter] = (x+1);

            }

            if (((y)>=0) && ((y)<=raw) && ((x-1)>=0) && ((x-1)<=col) && (OneZeros[y][x-1]==1) && (pf[y][x-1]==0))
            {
         counter++;
                pf[y][x-1] =OneZeros[y][x-1]*C;
                points[0][0][counter] = (y);
                points[1][0][counter] = (x-1);

            }


        }


        Count=counter;
        C ++;
    v2=lastCount+1;

    }



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




 Serial.println("///////////////////////////////////");
  Serial.println("The Map :");
for(int l=raw; l>=0; l--)
    {
        for(int k=0; k<=col ; k++)
        {


            Serial.print(pf[l][k]);
            Serial.print("   ");
        }
        Serial.println("");
        
    }

     Serial.println("");


 Serial.println("///////////////////////////////////");
















    int path[2][100][40]= {};
    int pathNo =1;
    int countx=0;
    v2 = 0 ;
    lastCount = 0;


    path[0][0][0] = start[0];
    path[1][0][0] = start[1];
    Count =0;
    int keepit=0;
    x=0;
    y=0;
    counter=0;




    while (pf[y][x]!=2)
    {

        lastCount = Count;
        countx++;


        for( int i = v2; i<=Count; i++)
        {
            y = path[0][i][countx-1];
            x = path[1][i][countx-1];

            if (((y+1)>=0) &&((y+1)<= raw) && ((x)>=0) && ((x)<=col) && (pf[y+1][x] == (pf[y][x]-1)))
            {




                for(int m=0; m<pathNo; m++)
                {
                    path[0][ pathNo ][ m] = path[0][i][m];
                    path[1][ pathNo ][ m] = path[1][i][m];
                }


                path [0][pathNo][countx]=y+1;
                path [1][pathNo][countx]=x;
                counter=counter+1;
                pathNo = pathNo+1;



            }

//////////////////////////////////////////





            if (((y-1)>=0) &&((y-1)<= raw) && ((x)>=0) && ((x)<=col) && (pf[y-1][x] == (pf[y][x]-1)))
            {

                for(int m=0; m<pathNo; m++)
                {
                    path[0][ pathNo ][ m] = path[0][i][m];
                    path[1][ pathNo ][ m] = path[1][i][m];
                }


                path [0][pathNo][countx]=y-1;
                path [1][pathNo][countx]=x;
                counter=counter+1;
                pathNo = pathNo+1;

            }
//////////////////////////////////////////

            if (((y)>=0) && ((y)<= raw) && ((x+1)>=0) && ((x+1)<=col) && (pf[y][x+1] == (pf[y][x]-1)))
            {


                for(int m=0; m<pathNo; m++)
                {
                    path[0][ pathNo ][ m] = path[0][i][m];
                    path[1][ pathNo ][ m] = path[1][i][m];
                }

                path [0][pathNo][countx]=y;
                path [1][pathNo][countx]=x+1;
                counter=counter+1;
                pathNo = pathNo + 1;



            }

//////////////////////////////////////////////
            if (((y)>=0) && ((y)<=raw) && ((x-1)>=0) && ((x-1)<=col) && (pf[y][x-1] == (pf[y][x]-1)))
            {

                for(int m=0; m<pathNo; m++)
                {
                    path[0][ pathNo ][ m] = path[0][i][m];
                    path[1][ pathNo ][ m] = path[1][i][m];
                }

                path [0][pathNo][countx]=y;
                path [1][pathNo][countx]=x-1;
                counter=counter+1;
                pathNo = pathNo + 1;


            }



        }

        Count=counter;
        v2 = lastCount+1;
        if(pf[y][x]!=2)
            keepit=Count;

    }

 /*  for(int l=0;l<2;l++)
      {
        for(int k=0;k<=Count;k++)
      {
          for(int m=0;m<=countx;m++)
      {
           Serial.print(path[l][k][m]);
             Serial.print(" ");
      }
        Serial.println("");
      }
      Serial.println("");
      }*/
/*Serial.print("Count= ");
Serial.println(Count);*/










    int valuey = Count-keepit;
    int valuex = countx+1;



    int LastPath[2][valuey][valuex];


    int q=0;
    int w=0;
    int e=0;


    for(int l =0; l<2; l++)
    {
        for(int i=(keepit+1); i<=Count; i++)
        {
            for(int k =0 ; k<=countx; k++)
            {
                LastPath[q][w][e] = path[l][i][k];

                e++;
            }
            e=0;

            w++;
        }
        w=0;
        q++;
    }

   /* 
 Serial.println("///////////////////////////////////");
Serial.println("LastPath");

   for(int l=0;l<2;l++)
      {
        for(int k=0;k<=Count-(keepit+1);k++)
      {
          for(int m=0;m<=countx;m++)
      {
           Serial.print(LastPath[l][k][m]);
             Serial.print(" ");
      }
        Serial.println("");
      }
      Serial.println("");
      }
       Serial.print("///////////////////////////////////");
       Serial.print("Count= ");
Serial.println(Count);


*/


    int a,b;
    int pathNav[30][100]={};



    for(int i=0; i<=valuey-1; i++)
        pathNav[i][0]=LastNavigation;



    for (int j=0; j<=valuey-1; j++)
    {
        for (int i=1; i<=valuex-1; i++)
        {
            a =LastPath[0][j][i] - LastPath[0][j][i-1];

            b =LastPath[1][j][i] - LastPath[1][j][i-1];

            if (a == 1 && b ==0)
            {
                pathNav[j][i] = 1;
            }

            else if (a == -1 && b == 0)
            {
                pathNav[j][i] = 2  ;
            }

            else if (a == 0 && b == 1)
            {
                pathNav[j][i] = 3;
            }

            else if (a == 0 && b ==-1)
            {
                pathNav[j][i] = 4;
            }


        }
    }
/*
  Serial.println("///////////////////////////////////");
  Serial.println("pathNav :");
   for(int k=0;k<=valuey-1;k++){
    for(int i=0;i<=valuex-1;i++){
  Serial.print(pathNav[k][i]);
         Serial.print(" ");
    }
   Serial.println("");
    }

  Serial.print("///////////////////////////////////");

*/


    
    




//////////////////////////////////
    int pathDir[20][100]={};



    for (int j=0; j<=valuey-1; j++)
    {
        for (int i=1; i<=valuex-1; i++)
        {
            a =pathNav[j][i-1];
            b =pathNav[j][i];

            if(a == 1 && b ==1 )
                pathDir[j][i-1] = 1;

            else if(a == 1 && b ==2 )
                pathDir[j][i-1] = 2;

            else if( a == 1 && b ==3)
                pathDir[j][i-1] = 3;

            else if( a == 1 && b ==4)
                pathDir[j][i-1] = 4;

/////////////////////////////////////////////////////////
            else if (a == 2 && b ==1 )
                pathDir[j][i-1] = 2;

            else if (a == 2 && b ==2)
                pathDir[j][i-1] = 1;

            else if (a == 2 && b ==3)
                pathDir[j][i-1] = 4;

            else if( a == 2 && b ==4)
                pathDir[j][i-1] = 3;

/////////////////////////////////////////////////////////
            else if (a == 3 && b ==1 )
                pathDir[j][i-1] = 4;

            else if (a == 3 && b ==2)
                pathDir[j][i-1] = 3;

            else if (a == 3 && b ==3)
                pathDir[j][i-1] = 1;

            else if (a == 3 && b ==4)
                pathDir[j][i-1] = 2;
/////////////////////////////////////////////////////////
            else if (a == 4 && b ==1)
                pathDir[j][i-1] = 3;

            else if (a == 4 && b ==2)
                pathDir[j][i-1] = 4;

            else if (a == 4 && b ==3)
                pathDir[j][i-1] = 2;

            else if (a == 4 && b ==4)
                pathDir[j][i-1] = 1;

        }

    }

/*
  Serial.println("///////////////////////////////////");
  Serial.println("pathDir :");
   for(int k=0;k<=valuey-1;k++){
    for(int i=0;i<=valuex-2;i++){
  Serial.print(pathDir[k][i]);
         Serial.print(" ");
    }
   Serial.println("");
    }

  Serial.println("///////////////////////////////////");
*/


    

///////////////////////////////////////
 int countOne=0;
    int Max=0;
    int Max_Location=0;

        for(int i=0; i<=valuex-2; i++)
            if(pathDir[0][i]==1)
                Max++;
 /* Serial.println("yyyyyyyyyyyyyyyyyyyyyyyyyyyy");
  Serial.println("yyyyyyyyyyyyyyyyyyyyyyyyyyyy");
  Serial.println(Max);
  Serial.println("yyyyyyyyyyyyyyyyyyyyyyyyyyyy");*/


    for(int k=0; k<=valuey-1; k++)
    {
        for(int i=0; i<=valuex-2; i++)
        {
            if(pathDir[k][i]==1)
                countOne++;


        }


            if(countOne>Max){
                Max_Location=k;
                Max= countOne;
            }
                countOne=0;
              
  /*Serial.println("qqqqqqqqqqqqqqq");
  Serial.println(Max_Location);
  Serial.println("qqqqqqqqqqqqqqq");*/
    }








    int FinalPath[100]={};

   

    for(int k=0; k<=valuex-2; k++)
        FinalPath[k]=pathDir[Max_Location][k];
        
    LastNavigation = pathNav[Max_Location][valuex-1];










    for(int i=IRC_CUNT; i<=(valuex-2+IRC_CUNT); i++)
      IRC[0][i]=FinalPath[i-IRC_CUNT];

    IRC_CUNT+=valuex-1;
    
    IRC[1][0]=LastNavigation;
    IRC[2][0]=IRC_CUNT;



/*
Serial.println("ttttttttttttttttttttt");
for(int l=8; l>=0 ; l--)
    {
        for(int k=0; k<5 ; k++)
        {


            Serial.print(pf[l][k]);
            Serial.print("   ");
        }
        Serial.println("");
        
    }
Serial.println("ttttttttttttttttttttt");

*/
/*
  Serial.println("///////////////////////////////////");
    Serial.println("IRC :");
    for(int k=0;k<=2;k++){
      for(int i=0; i<(IRC_CUNT); i++){
        Serial.print(IRC[k][i]);
        Serial.print(" ");
        }
        Serial.println("");
        }
  Serial.println("///////////////////////////////////");

*/

    Before_Last_Location[0] = LastPath[0][Max_Location][countx-1];
    Before_Last_Location[1] = LastPath[1][Max_Location][countx-1];
    Last_Location[0] = LastPath[0][Max_Location][countx];
    Last_Location[1] = LastPath[1][Max_Location][countx];
/*
  Serial.println("///////////////////////////////////");
  Serial.println("Before_Last_Location :");
    Serial.print( Before_Last_Location[0]);
    Serial.print(" ");
    Serial.println( Before_Last_Location[1]);
  Serial.println("///////////////////////////////////");
    Serial.println("///////////////////////////////////");
  Serial.println("Last_Location :");
    Serial.print( Last_Location[0]);
    Serial.print(" ");
    Serial.println( Last_Location[1]);
  Serial.println("///////////////////////////////////");

}*/
}

void IRC_Complete_Move(){



  
    OneZeros[GATE[0]][GATE[1]]=0;
    OneZeros[Box2_Dotnation[0]][Box2_Dotnation[1]]=0;
    OneZeros[8][4]=1;   
    OneZeros[6][0]=1;
    OneZeros[0][2]=1;
   //OneZeros[Box_Location[0]][Box_Location[1]]=0;
    IRC[1][0]=1;
    int finish[2];
 /////////////////////////////////////////////////   
     dueFlashStorage.write(1,IRC_CUNT);
     finish[0]= Box_Location[0];
     finish[1]= Box_Location[1];
path(OneZeros,9,6,start,finish,IRC[1][0]);
 ///////////////////////////////////////////////// 
  IRC[0][IRC_CUNT]=5;
  IRC_CUNT++;
  
 ///////////////////////////////////////////////// 
    // OneZeros[Box_Location[0]][Box_Location[1]]=0;
     start[0]= Before_Last_Location[0];
     start[1]= Before_Last_Location[1];
     finish[0]= Box_Dotnation[0];
     finish[1]= Box_Dotnation[1];
path(OneZeros,9,6,start,finish,IRC[1][0]);

 ///////////////////////////////////////////////// 
 
  IRC[0][IRC_CUNT]=6;
  IRC_CUNT++;
dueFlashStorage.write(2,IRC_CUNT);
 /////////////////////////////////////////////////
     OneZeros[GATE[0]][GATE[1]]=1;
    // OneZeros[Box_Location[0]][Box_Location[1]]=0;
     start[0]= Before_Last_Location[0];
     start[1]= Before_Last_Location[1];
     finish[0]= GATE[0];
     finish[1]= GATE[1];
path(OneZeros,9,6,start,finish,IRC[1][0]);

 ///////////////////////////////////////////////// 
  IRC[0][IRC_CUNT]=7;
  IRC_CUNT++;
 /////////////////////////////////////////////////

 
     start[0]= Last_Location[0];
     start[1]= Last_Location[1];
     finish[0]= Wait_Manual[0];
     finish[1]= Wait_Manual[1];
path(OneZeros,9,6,start,finish,IRC[1][0]);

 ///////////////////////////////////////////////// 
  IRC[0][IRC_CUNT]=8;
  IRC_CUNT++;
  dueFlashStorage.write(3,IRC_CUNT+1);
 ///////////////////////////////////////////////// 
     start[0]= Wait_Manual[0];
     start[1]= Wait_Manual[1];
     finish[0]= Box2_Location[0];
     finish[1]= Box2_Location[1];
path(OneZeros,9,6,start,finish,IRC[1][0]);
 ///////////////////////////////////////////////// 
  dueFlashStorage.write(4,IRC_CUNT);
  IRC[0][IRC_CUNT]=5;
  IRC_CUNT++;
  
   ///////////////////////////////////////////////// 
     OneZeros[Box2_Dotnation[0]][Box2_Dotnation[1]]=1;
     OneZeros[Box2_Location[0]][Box2_Location[1]]=0;
     start[0]= Before_Last_Location[0];
     start[1]= Before_Last_Location[1];
     finish[0]= Box2_Dotnation[0];
     finish[1]= Box2_Dotnation[1];
path(OneZeros,9,6,start,finish,IRC[1][0]);
 ///////////////////////////////////////////////// 
  IRC[0][IRC_CUNT]=9;
  IRC_CUNT++;
 ///////////////////////////////////////////////// 
 


    Serial.println("///////////////////////////////////");
    Serial.println("IRC :");
    for(int k=0;k<=2;k++){
      for(int i=0; i<(IRC_CUNT); i++){
        Serial.print(IRC[k][i]);
        Serial.print(" ");
        }
        Serial.println("");
        }
  Serial.println("///////////////////////////////////");

}

void IRC_Move(){
/*/  Serial.println("");
  Serial.println("START :");
  Serial.println(dueFlashStorage.read(increment)); 
  
  Serial.print("Number Of Moves :"); 
  Serial.println(dueFlashStorage.read(5)); 
*/
if (increment==1)
  Raise_Block=0;
else
  Raise_Block=1;

 for(int i=dueFlashStorage.read(increment);i<=dueFlashStorage.read(5);i++){
 // Serial.print("Move :");
  Serial.print(dueFlashStorage.read(i+6));
 }
  
  for(int i=dueFlashStorage.read(increment);i<=dueFlashStorage.read(5);i++){
 // Serial.print("Move :");
 //Serial.println(dueFlashStorage.read(i+6));
     //dueFlashStorage.write(0,i);
     
    if(dueFlashStorage.read(i+6)==1)
      Move_Straight();
    else if(dueFlashStorage.read(i+6)==2)
      Move_Backward();
    else if(dueFlashStorage.read(i+6)==3)
      Move_Right();
    else if(dueFlashStorage.read(i+6)==4)
      Move_Left();
    else if(dueFlashStorage.read(i+6)==5)
      Raise_Block1();
    else if(dueFlashStorage.read(i+6)==6)
      Leave_Block();
    else if(dueFlashStorage.read(i+6)==7)
      Open_Gate();
    else if(dueFlashStorage.read(i+6)==8)
      Wait_Manuel();
    else if(dueFlashStorage.read(i+6)==9)
      Leave_Block();
  }

  /* while (BL==1 && BR==1){
   Line_Following();
   // delay(300);
  }

   Stop();
  */
}
