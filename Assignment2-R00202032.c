//Cian Power
//R00202032

#include<stdio.h>
#include<stdlib.h>
int dice_roll()
{
    int num;
    X:num=rand()%7;
    // gets a random number between 0-6
    if(num==0)
    {
        goto X;
    }
    else{
        return num;
    }
}
void display_chart(int board,char player[4])
{ int i,y,x,z,rows=0,dice_num,position1;

 // Create the board
    for(i=10;i>0;i--)
    {
        x=i-1;
        if((rows%2)==0)
        {
            z=0;
            for(y=10;y>=1;y--)
            {
                dice_num=(i*y)+(x*z++);
 
                if(board==dice_num)
                {
                    printf("%s\t", player);
                }
                else{
                    printf("%d\t", dice_num);
                }
 
            }
            rows++;
        }
        else{
            z=9;
            for(y=1;y<=10;y++)
            {
                dice_num=(i*y)+(x*z--);
 
                if(board==dice_num)
                {
                    printf("%s\t", player);
                }
                else{
                    printf("%d\t", dice_num);
                }
            }
            rows++;
            }
        printf("\n\n");
    }
}
void main()
{
    int i,dice,cur_pos0=0,player_position=0,snakes,ladders; 
    char choice;
    printf("\n\n--------------------------------------------------------------\n");
    printf("\t\t\t    Snakes And Ladders\n");
    printf("--------------------------------------------------------------\n");
    FILE *fp = fopen("Results.txt", "w");
    fprintf(fp, "--Snakes And Ladders--\n");


    while(player_position != 100)

    {   
        printf("Snakes go from: | 74 to 14 | 45 to 22 | 99 to 10 |\nLadders go from:: | 5 to 18 | 33 to 68 | 80 to 93 |\n");
        dice=dice_roll();
		printf("\n\n------------------------------------------------------------------\n");
        printf("\t\t\t    Snakes And Ladders\n");
        printf("------------------------------------------------------------------\n");
        player_position=dice+player_position;
        if(player_position<101){
            fprintf(fp, "\nYou rolled a %d. You moved from %d to %d.", dice, (player_position-dice), player_position);
            if(player_position==99) //Snake
            {
                player_position = 10;
                display_chart(player_position,"*P1*");
                fprintf(fp, "\n\nUnlucky! You landed on a snake.");
                fprintf(fp, "\nYou slide down from 99 to %d.\n", player_position);
                
            }
            if(player_position==45) //Snake
            {
                player_position=22;
                display_chart(player_position,"*P1*");
                fprintf(fp, "\n\nUnlucky! You landed on a snake.");
                fprintf(fp, "\nYou slide down from 45 to %d.\n", player_position);
            }
            if(player_position==74) //Snake
            {
                player_position = 14;
                display_chart(player_position,"*P1*");
                fprintf(fp, "\n\nUnlucky! You landed on a snake.");
                fprintf(fp, "\nYou slide down from 74 to %d.\n", player_position);
            }
            if(player_position==80) //Ladder
            {
                player_position = 93;
                display_chart(player_position,"*P1*");
                fprintf(fp, "\n\nYou found on a ladder!");
                fprintf(fp, "\nYou climb up from 80 to %d.\n", player_position);
            }
            if(player_position==33) //Ladder
            {
                player_position = 68;
                display_chart(player_position,"*P1*");
                fprintf(fp, "\n\nYou found on a ladder!");
                fprintf(fp, "\nYou climb up from 33 to %d.\n", player_position);
            }
            if(player_position==5) //Ladder
            {
                player_position = 18;
                display_chart(player_position, "*P1*");
                fprintf(fp, "\n\nYou found on a ladder!");
                fprintf(fp, "\nYou climb up from 5 to %d.\n", player_position);
            }
            else{
                display_chart(player_position,"*P1*");
            }
            printf("\t\t\t\tDice = %d\n",dice);
            printf("--------------------------------------------------------------\n");
            if (player_position == 100) {
            fprintf(fp, "\n\nCongratulations, You won!");
            fclose(fp);
            }
        }
        else{
            player_position=player_position-dice;
            printf("Player 1 rolled too high.\n");
            display_chart(player_position,"*P1*");
            fprintf(fp, "\nYou rolled too high, you must go back to %d.", player_position);
        }
    }
}