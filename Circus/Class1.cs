using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

/**
 Circus Tower: A circus is designing a tower routine consisting of people standing atop one another's
shoulders. For practical and aesthetic reasons, each person must be both shorter and lighter
than the person below him or her. Given the heights and weights of each person in the circus, write
a method to compute the largest possible number of people in such a tower.
EXAMPLE
Input (ht, wt): (65, 100) (70, 150) (56, 90) (75, 190) (60, 95) (68, 110)
Output: The longest tower is length 6 and includes from top to bottom:
(56 J 90) (60J 95) (65J 100) (68J l10) (70J 150) (75J 190)
 */
namespace Circus
{
    class Class1
    {
        static int max(int a, int b) { return a > b ? a : b; }
        static List<Tuple<int,int>> findSequence(List<Tuple<int, int>> people, int bottom, Dictionary<int, List<Tuple<int, int>>> memo)
        {
            memo[bottom] = new List<Tuple<int, int>>();
            memo[bottom].Add(people[bottom]);
            Dictionary<int, int> heights = new Dictionary<int, int>();
            for (int i = bottom + 1; i < people.Count(); i++)
            {
                if (people[i].Item1 < people[bottom].Item1)
                {
                    if (!memo.ContainsKey(i))
                    {
                        memo[i] = findSequence(people, i, memo);
                    }
                    int height = 0;
                    foreach (var p in memo[i])
                    {
                        height += p.Item1;
                    }
                    heights[i] = height;
                }
            }
            int maxI = bottom;
            int maxHeight = 0;
            foreach(int index in heights.Keys)
            {
                if (heights[index] > maxHeight)
                {
                    maxHeight = heights[index];
                    maxI = index;
                }

            }
            if (maxI > bottom)
            {
                foreach (var person in memo[maxI])
                    memo[bottom].Add(person);
            }
            return memo[bottom];
        }
        static Tuple<List<Tuple<int, int>>, int> findBestTower(
            List<Tuple<int, int>> humans)
        {
            Dictionary<int, List<Tuple<int, int>>> memo = new Dictionary<int, List<Tuple<int, int>>>();
            int maxHeight = 0;
            int maxIndex = 0;
            for(int i=0; i<humans.Count(); i++)
            {
                if (!memo.ContainsKey(i))
                {
                    memo[i] = findSequence(humans, i, memo);
                }
                int localSum = 0;
                foreach(var person in memo[i])
                {
                    localSum += person.Item1;
                }
                if (localSum > maxHeight)
                    maxIndex = i;
                maxHeight = max(maxHeight, localSum);

            }

            return new Tuple<List<Tuple<int, int>>, int>(memo[maxIndex], maxHeight);
        }
        static void Main(string[] args)
        {
            // (65, 100)(70, 150)(56, 90)(75, 190)(60, 95)(68, 110)
            Tuple<int, int>[] collection = { // T1 = height, T2 = weight
                new Tuple<int,int>(65, 100),
                new Tuple<int,int>(70, 150),
                new Tuple<int,int>(56, 90),
                new Tuple<int,int>(75, 190),
                new Tuple<int,int>(60, 95),
                new Tuple<int,int>(68, 110) };

            List<Tuple<int, int>> people = new List<Tuple<int, int>>();
            foreach (var person in collection) // O(N)
                people.Add(person);

            people.Sort((a, b) => b.Item2.CompareTo(a.Item2)); // O(N LOGN) 

            foreach(var p in people)
            {
                Console.WriteLine(p.Item1 + " , " + p.Item2);
            }


            Tuple<List<Tuple<int, int>>, int> result = findBestTower(people); // T1 = tower list, T2 = tower height

            Console.WriteLine("Max height: " + result.Item2);
            foreach(var p in result.Item1)
            {
                Console.WriteLine(p.Item1 + " , " + p.Item2);
            }
        }
    }
}
