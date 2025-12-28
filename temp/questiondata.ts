export type Difficulty = "Easy" | "Medium" | "Hard";

export interface Problem {
  id: string;
  title: string;
  difficulty: Difficulty;
  platforms: {
    leetcode?: string;
    gfg?: string;
    codingNinjas?: string;
    spoj?: string;
    codechef?: string;
    codeforces?: string;
    hackerrank?: string;
  };
  topics?: string[];
}

export interface Topic {
  id: string;
  name: string;
  description: string;

  basic: Problem[];
  medium: Problem[];
  advanced: Problem[];
}

export const dsaTopics: Topic[] = [
  // heap
  {
    id: "heap",
    name: "Heap / Priority Queue",
    description:
      "Problems based on Min-Heap, Max-Heap, and Priority Queue techniques",

    basic: [
      {
        id: "heap-1",
        title: "Sort K Sorted Array",
        difficulty: "Easy",
        platforms: {},
        topics: ["Heap"],
      },
      {
        id: "heap-2",
        title: "Replace Each Array Element by Its Corresponding Rank",
        difficulty: "Easy",
        platforms: {},
        topics: ["Heap"],
      },
      {
        id: "heap-3",
        title: "Connect Ropes with Minimum Cost",
        difficulty: "Easy",
        platforms: {},
        topics: ["Heap"],
      },
    ],

    medium: [
      {
        id: "heap-4",
        title: "Introduction to Priority Queues using Binary Heaps",
        difficulty: "Medium",
        platforms: {},
        topics: ["Heap"],
      },
      {
        id: "heap-5",
        title: "Min Heap and Max Heap Implementation",
        difficulty: "Medium",
        platforms: {},
        topics: ["Heap"],
      },
      {
        id: "heap-6",
        title: "Check if an Array Represents a Min-Heap",
        difficulty: "Medium",
        platforms: {},
        topics: ["Heap"],
      },
      {
        id: "heap-7",
        title: "Convert Min Heap to Max Heap",
        difficulty: "Medium",
        platforms: {},
        topics: ["Heap"],
      },
      {
        id: "heap-8",
        title: "Kth Largest Element in an Array",
        difficulty: "Medium",
        platforms: {},
        topics: ["Heap"],
      },
      {
        id: "heap-9",
        title: "Kth Smallest Element in an Array",
        difficulty: "Medium",
        platforms: {},
        topics: ["Heap"],
      },
      {
        id: "heap-10",
        title: "Merge K Sorted Arrays",
        difficulty: "Medium",
        platforms: {},
        topics: ["Heap"],
      },
      {
        id: "heap-11",
        title: "Merge K Sorted Linked Lists",
        difficulty: "Medium",
        platforms: {},
        topics: ["Heap"],
      },
      {
        id: "heap-12",
        title: "Task Scheduler",
        difficulty: "Medium",
        platforms: {},
        topics: ["Heap"],
      },
      {
        id: "heap-13",
        title: "Hands of Straights",
        difficulty: "Medium",
        platforms: {},
        topics: ["Heap"],
      },
      {
        id: "heap-14",
        title: "Design Twitter",
        difficulty: "Medium",
        platforms: {},
        topics: ["Heap", "Design"],
      },
      {
        id: "heap-15",
        title: "Rearrange String to Avoid Adjacent Duplicates",
        difficulty: "Medium",
        platforms: {},
        topics: ["Heap"],
      },
      {
        id: "heap-16",
        title: "Top K Frequent Elements",
        difficulty: "Medium",
        platforms: {},
        topics: ["Heap"],
      },
      {
        id: "heap-17",
        title: "Kth Smallest Element in a Sorted Matrix",
        difficulty: "Medium",
        platforms: {},
        topics: ["Heap"],
      },

      /* added by me */
      {
        id: "heap-18",
        title: "Sliding Window Maximum",
        difficulty: "Medium",
        platforms: {},
        topics: ["Heap"],
      },
      {
        id: "heap-19",
        title: "Find K Closest Points to Origin",
        difficulty: "Medium",
        platforms: {},
        topics: ["Heap"],
      },
      {
        id: "heap-20",
        title: "Minimum Cost to Hire K Workers",
        difficulty: "Medium",
        platforms: {},
        topics: ["Heap"],
      },
    ],

    advanced: [
      {
        id: "heap-21",
        title: "Merge M Sorted Lists",
        difficulty: "Hard",
        platforms: {},
        topics: ["Heap"],
      },
      {
        id: "heap-22",
        title: "Kth Largest Element in a Stream",
        difficulty: "Hard",
        platforms: {},
        topics: ["Heap"],
      },
      {
        id: "heap-23",
        title: "Maximum Sum Combination",
        difficulty: "Hard",
        platforms: {},
        topics: ["Heap"],
      },
      {
        id: "heap-24",
        title: "Find Median from Data Stream",
        difficulty: "Hard",
        platforms: {},
        topics: ["Heap"],
      },

      /* added by me */
      {
        id: "heap-25",
        title: "Smallest Range Covering Elements from K Lists",
        difficulty: "Hard",
        platforms: {},
        topics: ["Heap"],
      },
      {
        id: "heap-26",
        title: "IPO (Maximize Capital)",
        difficulty: "Hard",
        platforms: {},
        topics: ["Heap"],
      },
      {
        id: "heap-27",
        title: "Ugly Number II",
        difficulty: "Hard",
        platforms: {},
        topics: ["Heap"],
      },
    ],
  },
  //  Greedy
  {
    id: "greedy",
    name: "Greedy",
    description:
      "Problems based on locally optimal choices leading to global optimum",
    basic: [
      {
        id: "greedy-1",
        title: "Assign Cookies",
        difficulty: "Easy",
        platforms: {
          leetcode: "https://leetcode.com/problems/assign-cookies/",
        },
        topics: ["Greedy"],
      },
      {
        id: "greedy-2",
        title: "Lemonade Change",
        difficulty: "Easy",
        platforms: {
          leetcode: "https://leetcode.com/problems/lemonade-change/",
        },
        topics: ["Greedy"],
      },
      {
        id: "greedy-3",
        title: "Jump Game",
        difficulty: "Easy",
        platforms: {
          leetcode: "https://leetcode.com/problems/jump-game/",
        },
        topics: ["Greedy", "Array"],
      },
      {
        id: "greedy-4",
        title: "Minimize the Sum of Product",
        difficulty: "Easy",
        platforms: {},
        topics: ["Greedy"],
      },
      {
        id: "greedy-5",
        title: "Largest Number Possible",
        difficulty: "Easy",
        platforms: {},
        topics: ["Greedy", "Sorting"],
      },
      {
        id: "greedy-6",
        title: "Minimum Number of Coins",
        difficulty: "Easy",
        platforms: {},
        topics: ["Greedy"],
      },
      {
        id: "greedy-7",
        title: "Can Place Flowers",
        difficulty: "Easy",
        platforms: {
          leetcode: "https://leetcode.com/problems/can-place-flowers/",
        },
        topics: ["Greedy"],
      },
    ],

    medium: [
      {
        id: "greedy-8",
        title: "Fractional Knapsack Problem",
        difficulty: "Medium",
        platforms: {
          gfg: "https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1",
        },
        topics: ["Greedy"],
      },
      {
        id: "greedy-9",
        title: "N Meetings in One Room",
        difficulty: "Medium",
        platforms: {
          gfg: "https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1",
        },
        topics: ["Greedy"],
      },
      {
        id: "greedy-10",
        title: "Jump Game II",
        difficulty: "Medium",
        platforms: {
          leetcode: "https://leetcode.com/problems/jump-game-ii/",
        },
        topics: ["Greedy"],
      },
      {
        id: "greedy-11",
        title: "Minimum Number of Platforms Required for a Railway",
        difficulty: "Medium",
        platforms: {
          gfg: "https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1",
        },
        topics: ["Greedy"],
      },
      {
        id: "greedy-12",
        title: "Job Sequencing Problem",
        difficulty: "Medium",
        platforms: {
          gfg: "https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1",
        },
        topics: ["Greedy"],
      },
      {
        id: "greedy-13",
        title: "Gas Station",
        difficulty: "Medium",
        platforms: {
          leetcode: "https://leetcode.com/problems/gas-station/",
        },
        topics: ["Greedy"],
      },
      {
        id: "greedy-14",
        title: "Activity Selection",
        difficulty: "Medium",
        platforms: {
          gfg: "https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1",
        },
        topics: ["Greedy"],
      },
      {
        id: "greedy-15",
        title: "Insert Interval",
        difficulty: "Medium",
        platforms: {
          leetcode: "https://leetcode.com/problems/insert-interval/",
        },
        topics: ["Greedy"],
      },
      {
        id: "greedy-16",
        title: "Merge Intervals",
        difficulty: "Medium",
        platforms: {
          leetcode: "https://leetcode.com/problems/merge-intervals/",
        },
        topics: ["Greedy"],
      },
      {
        id: "greedy-17",
        title: "Non-overlapping Intervals",
        difficulty: "Medium",
        platforms: {
          leetcode: "https://leetcode.com/problems/non-overlapping-intervals/",
        },
        topics: ["Greedy"],
      },
      {
        id: "greedy-18",
        title: "Boats to Save People",
        difficulty: "Medium",
        platforms: {
          leetcode: "https://leetcode.com/problems/boats-to-save-people/",
        },
        topics: ["Greedy"],
      },
      {
        id: "greedy-19",
        title: "Partition Labels",
        difficulty: "Medium",
        platforms: {
          leetcode: "https://leetcode.com/problems/partition-labels/",
        },
        topics: ["Greedy"],
      },
    ],

    advanced: [
      {
        id: "greedy-20",
        title: "Greedy Algorithm to Find Minimum Number of Coins",
        difficulty: "Hard",
        platforms: {
          gfg: "https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1",
        },
        topics: ["Greedy"],
      },
      {
        id: "greedy-21",
        title: "Candy",
        difficulty: "Hard",
        platforms: {
          leetcode: "https://leetcode.com/problems/candy/",
        },
        topics: ["Greedy"],
      },
      {
        id: "greedy-22",
        title: "Valid Parenthesis Checker",
        difficulty: "Hard",
        platforms: {},
        topics: ["Greedy", "Stack"],
      },
      {
        id: "greedy-23",
        title: "Huffman Encoding",
        difficulty: "Hard",
        platforms: {
          gfg: "https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1",
        },
        topics: ["Greedy"],
      },
      {
        id: "greedy-24",
        title: "Minimum Arrows to Burst Balloons",
        difficulty: "Hard",
        platforms: {
          leetcode:
            "https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/",
        },
        topics: ["Greedy"],
      },
      {
        id: "greedy-25",
        title: "Queue Reconstruction by Height",
        difficulty: "Hard",
        platforms: {
          leetcode:
            "https://leetcode.com/problems/queue-reconstruction-by-height/",
        },
        topics: ["Greedy"],
      },
      {
        id: "greedy-26",
        title: "Reduce Array Size to The Half",
        difficulty: "Hard",
        platforms: {
          leetcode:
            "https://leetcode.com/problems/reduce-array-size-to-the-half/",
        },
        topics: ["Greedy"],
      },
    ],
  },
];
