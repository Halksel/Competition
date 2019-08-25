using System;
using System.Linq;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;

/**
 * This code automatically collects game data in an infinite loop.
 * It uses the standard input to place data into the game variables such as x and y.
 * YOU DO NOT NEED TO MODIFY THE INITIALIZATION OF THE GAME VARIABLES.
 **/
class Player
{
    static void Main(string[] args)
    {
        int thrust = 100;
        bool boosted = false;
        Func<int, int, int, int, double> Distance = (x, y, nx, ny) => (x - nx) ^ 2 + (y - ny) ^ 2;
        const double Deg2Rad = Math.PI / 180;
        // game loop
        while (true)
        {
            string[] inputs = Console.ReadLine().Split(' ');
            int x = int.Parse(inputs[0]); // x position of your pod
            int y = int.Parse(inputs[1]); // y position of your pod
            int nextCheckpointX = int.Parse(inputs[2]); // x position of the next check point
            int nextCheckpointY = int.Parse(inputs[3]); // y position of the next check point
            int dist = int.Parse(inputs[4]);
            int angle = int.Parse(inputs[5]);
            inputs = Console.ReadLine().Split(' ');
            int ox = int.Parse(inputs[0]); // x position of your pod
            int oy = int.Parse(inputs[1]); // y position of your pod

            // Write an action using Console.WriteLine()
            // To debug: Console.Error.WriteLine("Debug messages...");
            angle = Math.Abs(angle);
            angle = angle > 90 ? 90 : angle;
            Console.Error.WriteLine(angle);

            int baseThrust = 70;

            thrust = (int)(Math.Cos(angle * Deg2Rad) * baseThrust) + (100 - baseThrust);
            thrust = thrust > baseThrust ? 100 : thrust;

            // Edit this line to output the target position
            // and thrust (0 <= thrust <= 100)
            // i.e.: "x y thrust"
            if (!boosted && Math.Abs(angle) < 20 && dist > 3000)
            {
                boosted = true;
                Console.WriteLine(nextCheckpointX + " " + nextCheckpointY + " BOOST");
            }
            else
            {
                Console.WriteLine(nextCheckpointX + " " + nextCheckpointY + " " + thrust);
            }
        }
    }
}