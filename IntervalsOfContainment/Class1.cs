using System;
using System.Collections;
using System.Collections.Generic;

namespace Px
{
    public class IntervalsOfContainment
    {
        public readonly struct interval
        {
            public interval(int left, int right)
            {
                this.left = left;
                this.right = right;
            }
            readonly int left;
            readonly int right;

            public int getRight()
            {
                return this.right;
            }

            public int getLeft()
            {
                return this.left;
            }
            public bool contains(interval other)
            {
                return this.left <= other.left && this.right >= other.right;
            }

            public static bool operator<(interval left, interval right)
            {
                if (left.getLeft() < right.getLeft())
                    return true;
                if (left.getLeft() == right.getLeft())
                {
                    if (left.getRight() < right.getRight())
                        return false;
                    return true;
                }
                return false;
            }

            public static bool operator>(interval left, interval right)
            {
                return right < left;
            }

            public string print()
            {
                return "[ " + this.getLeft() + " , " + this.getRight() + " ]";
            } 
        }


        public class intervalComparator : Comparer<interval>
        {
            public override int Compare(interval left, interval right)
            {
                if (left.getLeft() < right.getLeft())
                    return -1;
                if (left.getLeft() == right.getLeft())
                {
                    if (left.getRight() < right.getRight())
                        return +1;
                    return -1;
                }
                return +1;
            }
        }
        public static void Main(string[] args)
        {
            interval[] ranges = new interval[]
            {
                new interval(3,5), new interval(2,5), new interval(5,9), new interval(1,3), new interval(3,7),
                new interval(6,8), new interval(2,4), new interval(5,8), new interval(2,6), new interval(8,9),
                new interval(4, 5)
            };
            int size = 11;

            foreach(interval i in ranges){
                Console.WriteLine(i.print());
            }

            Array.Sort(ranges, new intervalComparator());
            Console.WriteLine("----------------------------");
            foreach (interval i in ranges)
            {
                Console.WriteLine(i.print());
            }

            ArrayList solution = new ArrayList();

            for(int n = size-1; n >= 0; n--)
            {
                for(int i = 0; i<n; i++)
                {
                    if (ranges[i].contains(ranges[n]))
                    {
                        solution.Add(ranges[n]);
                        break;
                    }
                }
            }

            Console.WriteLine("----------SOL-----------");
            Console.WriteLine(solution.Count);
            foreach (interval i in solution)
                Console.WriteLine(i.print());

        }


}
}
