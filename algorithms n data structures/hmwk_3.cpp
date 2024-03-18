//
//  main.cpp
//  alg hmwk 3
//
//  Created by Autumn Tiede on 12/3/23.
//

#include <iostream>
#include <chrono> // timing
using namespace std;
using namespace std::chrono;

void bubbleSort(int arr[], int size, int& swapCount) {
    // loop to access each array element
    for (int step = 0; step < (size - 1); ++step) {

        // check if swapping occurs
        int swapped = 0;

        // loop to compare two elements
        for (int i = 0; i < (size - step - 1); ++i) {

            // compare two array elements
            // change > to < to sort in descending order
            if (arr[i] > arr[i + 1]) {

                // swapping occurs if elements
                // are not in intended order
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;

                swapped = 1;
                swapCount++;
            }
        }

        // no swapping means the array is already sorted
        // so no need for further comparison
        if (swapped == 0)
            break;
    }
}

// shell sort
void shellSort(int arr[], int n, int& swapCount_shell) {
    swapCount_shell = 0;

    for (int g = n / 2; g > 0; g /= 2) {
        for (int i = g; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= g && arr[j - g] > temp; j -= g) {
                arr[j] = arr[j - g];
                swapCount_shell++;
            }
            arr[j] = temp;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


int main(){
    int swapCount_shell, swapCount_bubble;
    int arr[] = {4494,2481,2919,1504,2291,801,3487,3362,1717,446,482,2097,1798,3006,3983,4419,3216,3845,1512,4923,2943,3815,3675,4078,3423,3064,1372,3934,1027,2527,4453,524,2970,3411,1953,2070,4947,2728,2197,2005,1207,3567,1589,2294,1762,2048,905,1663,4577,2985,1726,722,4991,64,2534,466,3139,3577,4155,2911,2762,1026,4497,4332,786,3737,2407,4265,1833,1608,3822,2748,1937,4797,4935,4344,3277,4859,372,419,4524,1551,1659,4582,4271,3627,1129,2243,2198,3889,2351,4647,3654,1044,1603,4299,177,3062,2164,258,2418,2387,114,4681,3857,670,143,4168,939,3358,937,60,1331,2300,2193,2821,4944,1790,254,1553,2992,2754,2556,3874,4718,2223,1403,3968,2680,2576,3184,470,4616,4620,3349,3330,4803,337,3689,512,1642,2776,2260,1221,302,4408,3224,824,3012,2316,1712,2149,706,3692,681,3731,1787,2997,1304,1799,32,4045,4163,2062,1929,2987,3582,2896,1797,3693,4877,4375,1596,3687,1463,4567,3300,2092,1909,4512,4913,4220,2483,220,3547,4446,104,1177,2389,612,4340,310,839,336,565,3977,4634,3668,3813,3355,3370,4182,1788,2496,4960,2138,2162,1340,1500,2219,2268,407,2560,2330,231,4491,1313,2108,589,426,1112,2887,4682,3769,3840,4295,1875,4767,107,773,2013,2296,2461,2873,30,4728,3614,3428,2237,1698,3897,2633,2178,3917,3132,966,4671,1414,4393,2836,412,1503,1895,3105,866,4980,1367,475,1525,3280,1944,4830,1822,2532,1692,1995,1989,17,1552,2549,3519,993,2403,4050,781,4255,4029,1448,471,3276,684,2161,3806,4950,4278,6,3456,1534,1015,4953,3122,3425,3798,3809,3306,3964,2604,2640,1316,3724,1526,19,1843,4174,4363,2623,4436,3858,4613,494,4321,3792,2293,2049,1353,3071,1587,4383,4013,2392,171,1368,2315,4291,682,4342,133,2745,2364,47,2627,2862,920,3550,2347,4539,4490,241,782,2930,4175,4331,4215,3102,100,4720,4747,1120,3191,1328,4242,3217,2127,1590,4219,1173,1159,1494,4829,3939,3909,278,2022,1647,4097,3421,1239,1089,2691,293,759,1826,4583,4623,733,1394,3984,200,3869,3455,2617,4753,3189,68,911,81,3608,3542,2319,2892,806,2467,4420,2443,4390,655,3601,2459,3764,3976,281,2218,1959,3464,2076,4021,2251,3831,2512,4249,3648,3507,2825,3078,342,3352,2649,837,1387,2168,3032,308,2345,2622,33,2225,4548,850,4079,3251,929,3401,3741,3112,1140,314,3677,3057,4493,3735,201,3021,4014,1180,4044,3363,2535,2678,1585,3650,3424,1794,1272,1381,2790,376,2051,1135,4592,596,2192,4666,2996,3043,1001,1616,2104,2036,2787,4544,750,1760,718,695,2118,1775,164,4585,822,1342,4654,3221,4712,4447,2689,4303,371,3354,3637,1644,3656,1795,1674,1101,129,1270,3075,46,4879,1882,4678,2194,2021,3508,3157,1194,3081,416,483,175,4812,2393,428,154,2641,4852,3404,2619,2995,355,458,4909,3150,3631,4619,4,71,2688,2797,1094,1096,1820,1885,4978,3263,2375,2646,2844,633,4012,598,476,637,3198,912,4745,2723,1146,4721,3384,3023,3340,1334,1802,3915,4775,3039,1211,1864,1040,4411,1777,2380,4001,53,4280,4799,2968,233,3634,4062,2252,2334,4779,1196,2629,3133,3742,2583,2247,2876,486,720,2290,3973,3369,1103,87,1521,3271,1123,425,4940,3226,3098,1830,1216,2083,1561,1080,272,1713,983,3524,1759,1338,2701,1580,3715,1069,1888,3215,856,1000,3994,3527,2811,678,1405,2034,3063,1563,4722,176,3440,2955,683,3171,1951,1311,1233,3490,2658,202,136,1675,771,1846,132,2548,3699,1514,505,3453,3469,2271,217,1935,4109,4086,3077,417,3620,1893,3902,4430,3438,4710,13,3942,2522,4183,1643,4584,2894,2003,804,1412,499,761,253,590,689,921,741,3357,73,1360,4520,2448,865,4556,1032,4929,4016,2546,1947,4069,2433,3315,83,4055,4205,3361,3953,3959,1629,2355,4338,4018,4717,1346,4912,2542,3949,1550,2613,1683,3197,1450,1142,2718,4083,174,2122,3180,1265,3812,98,503,3146,1771,1182,4421,2710,3970,887,3799,3326,1792,264,2420,3597,4580,1453,1981,2329,1735,3533,2886,935,2306,128,928,1872,2066,4924,1475,2884,3783,1862,3443,2150,1996,1118,3065,4515,3674,825,2719,4057,2585,4334,2518,3458,1245,4565,4023,110,1868,1263,4808,3700,1651,1478,4805,4826,846,3960,1055,206,4772,1423,737,1167,459,3392,1203,4223,2452,4484,1499,811,985,2781,1592,3252,435,2993,3754,4346,1355,1686,3072,3093,2321,3092,981,423,2555,2697,2343,3407,1825,2464,4625,4857,4898,2476,1486,3172,1627,2278,4300,1544,1205,2715,4892,662,2830,1401,4122,1732,2437,608,1646,1992,4465,3465,3264,763,595,3862,95,4323,566,4031,1237,3130,4564,4916,3615,836,2590,2159,1988,2140,3127,3756,4179,2981,3281,4397,4056,3564,285,537,2032,3854,2205,3448,2186,2937,4807,1583,4369,946,1714,2537,4649,2913,1998,4884,2957,3578,1033,3332,2703,587,903,3990,62,833,89,257,4771,1576,4176,775,2440,1424,2871,3484,3046,2307,1701,4530,2111,229,4570,4308,2147,3946,703,3925,708,4105,2700,1558,4550,4508,2893,29,826,3919,3170,211,2187,572,125,1441,2679,2588,4241,1852,1774,4441,2154,2348,408,3495,3160,1073,3884,840,147,3398,1459,472,414,65,4263,1889,4813,4910,3924,4477,1347,2675,1898,3477,1217,2220,1043,1106,523,988,75,3188,1268,4333,4558,3164,1628,2648,820,1650,1615,2705,2632,4936,2327,1640,4134,2432,4370,300,2667,4579,3581,2272,739,4444,1780,1842,2063,1288,3844,2368,742,1942,3621,1111,4824,546,3439,1358,1345,3546,1351,3638,2071,1709,1719,4878,1618,2569,4522,2107,1134,3462,4664,2085,2214,4762,4961,2586,2148,485,492,400,1172,2509,2519,3479,2423,1536,4099,3095,2446,1398,1690,3913,1661,2312,4142,2900,3409,453,4152,2746,2681,2055,760,4816,3322,3632,4474,1491,1594,4559,3104,1250,4443,3852,2739,1723,3928,2864,346,4025,88,1657,2977,3192,4886,349,2320,3113,1718,2948,1309,3181,961,16,4487,1278,158,1066,3233,1946,2756,23,3788,561,320,1955,2929,3454,4670,1018,4780,2863,2874,387,1808,2170,1332,204,3004,78,4997,2851,4298,2822,3795,3569,4814,1006,2208,2473,1393,4784,4496,4296,443,4194,4770,4643,3028,3515,4104,4081,2744,1228,3797,1819,2052,2991,1392,3049,1144,4499,3992,39,465,1315,4454,3855,885,4686,4426,4552,4087,2302,3187,4653,1523,1613,2575,1349,666,3087,3460,3451,1969,2074,1734,4928,3341,1008,1336,3173,2176,574,2377,170,4036,701,1231,2889,828,230,3810,1467,4063,628,4129,4228,1235,109,1720,1768,3506,279,516,2445,3864,338,167,2741,2256,3101,4789,4679,1171,878,3894,2525,316,650,2778,82,613,2601,1923,4863,767,2774,1672,1350,2304,1498,4846,1184,2541,4751,356,2470,2661,37,3353,1956,1174,1926,4377,1711,4926,2538,4606,2712,2398,4196,1145,947,2980,1559,2618,4629,2885,592,3144,370,4161,3153,2711,1804,1206,1293,4674,2413,660,3568,4353,3595,851,1809,2121,2651,4460,21,277,842,4238,4111,4276,4662,3965,4355,1482,1617,3544,4343,2834,3747,2035,3378,1699,3666,1458,2287,4218,2323,437,1876,4917,686,2909,2239,4117,800,329,3342,2890,2624,3868,4714,688,2124,4279,698,3109,4685,4410,323,2965,3937,906,3140,67,150,2016,352,1990,3999,2212,847,4692,4366,1986,74,3245,1072,3073,951,4593,2279,818,2482,1665,3393,2079,1365,1020,1038,721,997,3437,4651,643,694,106,2570,3775,266,4915,4123,3243,3816,2564,3670,3309,4785,835,1867,2241,4823,1395,45,111,3826,2729,881,367,92,1195,2510,507,1891,607,810,2199,4549,4116,4251,3305,194,2528,919,4501,4655,1549,4869,384,4609,1821,193,1200,533,2520,4070,344,263,4965,4019,3432,1517,275,690,1778,756,3651,477,2733,4399,2805,2999,2545,377,3234,4147,4404,1275,3118,2910,758,4760,4113,190,4873,3295,909,1656,719,1649,3661,4051,2721,2054,2521,3318,2025,3223,1571,890,2493,3991,350,2791,3084,4160,2200,2224,4405,1884,2116,252,219,1532,3068,2847,4158,1973,4005,4131,668,4463,3819,1327,4594,2131,1919,1538,2897,3346,2559,1230,1204,743,243,1201,2750,2647,4998,238,451,1886,2056,2311,139,568,2832,934,2365,4358,3770,575,948,1432,1014,3559,658,321,2486,3459,4394,1406,3383,1188,2490,1497,2037,80,3900,441,923,979,118,2857,456,2144,4514,844,3080,1575,3323,2615,4171,4607,2449,3254,291,3920,711,699,2636,490,1009,4705,198,4525,1965,4261,2933,4222,1161,4254,1599,606,4003,3943,4683,4439,4765,2184,704,4151,4867,4413,3606,351,1740,3536,894,4456,1294,2363,2988,50,1952,4700,4870,2078,2396,24,4854,797,1737,3980,1773,422,2386,3176,857,4553,1977,4802,861,2246,4396,597,3106,3853,4121,2563,3879,2888,1222,1083,2280,4088,4511,2540,1359,1918,4213,1343,1473,1911,998,2276,2367,4768,2230,3270,3445,2976,1695,2275,4844,4329,1637,3969,2938,4741,1834,491,1449,3539,3185,4517,2978,3794,4545,4701,3820,1975,3218,564,3158,1715,381,3892,4856,4810,90,2414,3103,4232,1045,4757,3311,2950,131,1156,1772,4007,4615,3292,2061,43,3285,2807,1244,4595,1354,1036,3786,978,2361,3633,2854,2792,4510,3664,1422,4949,146,3010,2599,2098,4379,1635,4845,2663,674,123,2382,2799,66,3359,1192,1810,3261,4237,1249,4526,3372,3787,1903,409,322,980,926,2264,1389,2409,2090,3718,957,3958,4974,216,1860,2881,2195,1584,4906,1837,2626,440,4597,2128,622,347,2775,2738,1667,2671,1446,2963,3579,1658,2139,3776,1344,4840,331,2578,1016,2806,765,571,2986,504,888,1285,3452,4640,529,4316,4986,1242,751,4400,527,876,3446,2964,1887,4432,3617,1282,3031,1193,987,2130,2714,4505,2207,2865,2106,1921,3997,4641,3652,1997,2171,3728,3655,34,366,3320,2045,2117,4861,395,3115,2620,1054,113,3811,3100,644,2415,2472,4561,115,2704,1577,4424,3587,4239,4290,2998,2579,4080,1409,4507,166,1246,2112,3262,1126,2426,41,2009,3591,1524,584,1920,4964,3523,2861,4516,240,1970,102,3413,3906,2469,1855,3159,4731,185,3435,4258,1716,3834,2717,5,2305,1303,1474,134,1115,2925,3987,594,1319,1654,3499,526,1227,736,4880,358,1091,2783,330,3255,248,617,448,1519,4154,1591,3696,1813,274,916,1434,4352,852,1276,3847,1901,1273,3698,382,2402,4434,1485,671,3623,4984,2073,2809,86,4204,4908,1215,3154,1922,4587,245,508,484,3893,3463,2480,4266,2046,4039,1388,813,2211,2100,1472,2333,1660,4259,369,2133,532,3335,2609,3069,4589,870,2261,4112,745,2169,2869,2027,2057,4885,1601,234,2730,93,4996,2979,4749,2286,4240,3381,1310,2650,2643,3179,3366,3007,3396,896,4041,1439,1539,4047,2340,2808,1648,1469,576,4979,3540,1668,770,696,368,1899,2536,138,3829,3962,1632,303,4684,3875,1611,3016,1516,1894,3899,2608,4868,4631,1382,4730,1479,3117,4489,702,2568,995,3790,3907,3500,3422,4250,1748,4656,3400,3758,3327,2269,814,3414,1708,4644,793,51,2734,2543,103,807,4743,3253,1493,3165,823,2337,1915,611,4395,3481,616,3671,4407,1419,3723,3343,2080,2789,438,2103,3002,394,3034,2935,1579,4825,3120,2065,3649,1333,1655,3268,1602,2039,3562,4973,2606,518,20,120,4189,4739,1185,1226,1352,3684,4073,2587,2067,2399,4754,3688,754,1287,4827,893,4707,1685,3312,1471,2645,4698,1931,2245,4756,3368,1776,1330,1013,3294,3774,4028,4468,1578,3589,1284,3236,4946,1908,535,1736,3995,4288,2747,3667,4156,4503,3211,889,1508,4458,2784,542,4618,452,1916,2639,149,3929,1148,4246,1604,3720,2798,3430,2277,1823,3099,2516,393,4437,2984,4428,3846,4665,1865,3222,2328,101,4903,406,1767,548,1088,144,3321,4699,2236,4233,2882,964,4995,3771,4120,2298,659,938,915,2292,4952,4180,2853,1132,1914,3709,2203,2558,4283,4551,4837,1511,4543,534,4820,3478,785,989,2227,4269,1037,3975,3978,619,2113,799,2379,2135,1976,3730,757,2284,3765,3375,3155,4438,4450,1320,2373,832,4202,4216,1978,1769,1841,1678,936,4498,2530,4185,2254,3220,3624,2969,1329,3750,2183,270,3134,4336,3196,4601,2400,9,2932,3336,3297,1427,208,3708,2840,1348,3535,1324,831,3470,4729,2653,2072,2479,3817,235,4461,821,1622,1236,379,2068,1861,1302,1121,4832,1004,3933,3232,1058,1531,1229,319,4495,2384,3971,4572,2793,1703,4033,4713,2833,3772,214,3242,354,3576,2088,4224,1092,3231,2002,4920,710,1179,4262,4989,1847,467,1502,3916,2731,4966,895,3690,315,4798,3566,3993,1296,2924,3350,430,3142,2659,460,2912,14,2655,374,2201,4541,1721,4193,1290,795,1100,1562,3755,3839,3208,4061,4114,1468,3673,2693,570,3468,3580,4963,1607,3695,585,4636,4140,3599,1849,3356,2185,734,2923,2222,267,3966,2566,1152,4948,853,57,3206,2489,4469,798,790,2463,4256,3618,1411,3480,1466,1754,1035,184,1954,3054,2947,2442,1098,3522,2595,796,1906,1902,1700,2020,4210,1247,1124,3076,3227,1605,3482,3706,169,4608,1964,3828,2502,1625,2544,3373,4227,3713,4622,4734,509,1104,4930,2593,2335,3914,2843,1396,1742,1609,457,4326,4143,1046,1791,627,4059,2242,4133,1219,2500,3082,11,2597,2695,2456,487,892,1495,2953,1993,805,1487,3225,3807,777,2684,489,2735,1261,2928,4630,3195,4448,1581,3639,1454,789,2028,1082,727,3895,1099,4687,1569,2656,4842,3079,4118,1949,652,2358,3622,4847,4137,3630,4172,1483,4817,973,2716,3732,3682,2105,2664,3207,4893,525,3644,1299,554,3339,2973,4782,389,3530,4708,602,390,730,1832,1041,1456,1782,3387,3274,4391,3572,1623,1835,3009,3033,464,2086,1075,2282,2837,4919,4617,4865,4695,1488,3213,4128,3777,3420,2944,2803,4574,685,4235,1238,4737,2989,3418,2390,1213,3128,130,2317,539,2589,1555,3876,632,97,4941,2263,3594,1442,558,1110,4423,4635,1051,707,748,1136,3877,2634,762,4921,952,3935,2598,3025,1645,2592,886,261,4809,3406,4835,4591,3918,4170,187,1556,1133,3329,2551,2274,779,2514,54,3001,4387,3814,3517,3584,1789,4838,1181,1950,3166,2954,2281,2503,3883,2289,2945,3859,4368,4521,2802,4970,1102,3391,4740,849,2936,2841,3344,4488,4971,2785,260,4212,2240,1980,4206,3125,1910,4697,4119,250,4850,3629,3278,1800,2916,4937,2580,3167,4645,153,974,676,38,2257,958,212,3645,536,1105,2895,1189,2706,1,4127,313,2550,959,545,468,3119,2816,4650,3380,4554,2129,4096,424,142,769,91,4602,4264,3773,4839,1052,4975,4422,2017,1566,473,2508,1279,3930,2157,1987,1691,2359,4425,3881,3612,77,1397,4195,2153,4819,4072,2761,669,450,1764,4557,2458,3136,3662,411,2855,2552,673,4773,3880,1252,3337,3957,1262,1743,1515,4367,4744,3416,2687,4392,4627,1600,3843,4537,4032,1443,4115,3489,514,140,2891,4412,3377,1781,3074,2501,2372,1966,4851,3804,1462,2018,604,3200,965,2000,3988,1943,1733,1162,3549,3267,4529,421,4706,4272,2949,3441,3476,3491,3442,2095,2429,2362,1744,4889,3307,2485,990,3643,410,3141,747,4234,728,2867,4139,3030,1724,2625,3676,620,3345,116,4588,1029,4376,2752,2008,3447,933,4297,2742,1064,2421,2666,4359,4190,415,1662,868,2795,2820,3047,1960,4990,4763,843,3733,4322,1003,1298,1863,1373,898,3719,1266,4742,1936,4106,1702,766,2466,172,2845,3161,502,749,3045,2722,4901,1109,559,3998,3086,817,4144,1805,1378,3702,1408,1853,752,4416,2332,3955,3714,1283,335,3194,2007,4141,3203,2637,4042,729,1505,2451,4504,1312,271,4085,4445,124,22,3558,1729,4150,1564,3288,4010,4736,3014,4009,4860,4646,1766,3502,962,3019,4925,1289,1086,3266,4034,162,2850,540,498,1374,4211,3609,1433,4431,2594,2685,1164,3055,2425,1071,3275,4914,4402,538,2934,3592,2381,3628,3041,1738,3279,2547,4294,838,1198,2771,3641,2577,3265,3205,3961,2856,2926,1971,4093,3849,290,2494,2497,1011,1793,1983,631,4076,4774,2190,3513,4309,1765,3299,4849,2927,1509,2126,1572,3685,3757,3250,2914,2505,1679,3752,2901,4663,1410,2815,357,917,723,609,4103,85,672,3926,1827,2917,3474,3015,1452,2322,3328,380,4373,3509,4270,3873,3867,4136,4724,4372,2024,3585,10,812,1077,4024,625,4951,1307,4389,520,1220,3707,1435,2975,1900,4324,930,4409,3950,4077,3024,3029,882,1240,827,819,700,1079,1492,4612,3501,2796,3796,3818,1056,4418,2094,4624,3553,1932,469,1017,2529,1210,1274,588,4821,4875,15,427,1208,3551,4716,2657,332,2089,4173,4661,2395,273,2406,4188,738,265,2324,3697,713,2960,645,1752,1122,94,2385,99,2846,753,4341,4470,2417,4788,4911,4230,1139,2374,8,3303,922,2612,3505,3415,2524,4401,1209,4806,2506,3555,1933,1593,3944,3979,3908,2369,2848,3725,3694,732,4325,4100,3805,1972,639,4022,1199,1527,4637,324,4709,221,1545,3210,280,2397,191,4314,651,4610,999,1501,4385,3121,3825,3376,1375,515,2831,1301,744,2773,2720,1626,3871,1402,309,4967,2760,3473,4365,2571,1050,746,4786,2179,4500,4184,2087,2690,863,1440,2004,2428,3248,541,3782,2155,1682,3736,1619,48,4599,1404,2860,2285,3287,940,1784,1021,1934,3450,4388,4149,1061,2371,3511,317,3647,40,1300,1197,4904,3212,1007,913,4268,148,399,3561,1225,1706,648,549,2258,4652,2204,2838,3131,1153,1606,4834,3870,1506,3726,4178,4848,1568,1012,1770,880,4890,2014,1074,1669,4040,3149,3427,1961,4225,510,1062,1223,2498,2465,3201,4357,2012,3123,61,1431,1670,2769,2455,76,4286,3573,941,2582,1557,4004,4828,173,3492,27,2010,3000,2702,4328,3672,4414,2360,3331,829,1143,2091,2801,4862,1728,4711,4307,4876,2391,1326,4690,3681,2966,3856,1264,3848,404,3766,2156,2673,3239,2765,2732,982,2990,375,4723,864,1445,1165,2898,2006,4315,1541,1163,634,4927,2764,1673,4748,2101,2339,3660,3051,3891,3571,4030,4132,2026,2096,591,3679,4509,2491,4406,108,1005,1945,2234,803,693,4719,2708,599,2829,105,976,4769,859,2642,2533,2404,442,2416,1840,439,4095,4843,4506,2786,3940,3485,3888,4017,481,3410,3083,3379,1941,970,4483,3498,557,4066,4074,3175,1904,2450,780,2166,2621,1386,4382,2487,2093,1652,1297,3035,4317,4000,1979,4982,1377,3531,2828,4252,1928,2349,3521,259,2707,4693,4481,2244,2644,3604,1369,3067,434,630,808,2422,635,2435,4275,4486,4648,2270,3089,992,196,872,3397,1426,1010,4319,495,2905,262,2777,2050,2233,188,519,4337,3548,932,2478,1455,1595,2567,3199,716,4058,4673,4479,2438,1818,318,4833,1948,2779,553,186,3646,4691,1630,3538,3931,4871,2181,792,914,1022,3488,2736,2727,1994,3403,1763,4590,4452,84,392,975,4897,3013,1897,1049,1248,4214,402,2511,4605,4002,4738,2858,1255,4381,1704,296,3317,2823,383,2804,1869,4531,984,4519,373,3663,3974,4502,3429,1376,1879,3729,4169,3017,4049,3850,2,1234,203,3126,2670,4563,155,222,1653,3070,677,4138,2180,4198,4455,871,1999,3385,3090,3289,334,3053,3338,858,3981,433,4573,3466,1477,2191,563,2142,900,3516,855,1437,640,2614,2297,582,2474,4267,1612,79,3841,3780,4181,2758,1857,2221,4801,3657,1383,4902,4197,3202,1801,4999,4899,3174,1031,2504,276,2766,1582,3283,1812,4905,2574,2780,2266,4284,531,4312,945,3710,4943,1157,601,2038,3705,3088,2081,897,3467,4380,2401,127,1113,4581,724,3282,4864,2737,2041,1379,869,3613,1807,1554,1858,4274,2635,283,3537,1421,2835,3091,3494,3910,783,4672,4285,2674,3866,1063,4247,3291,1169,2962,3048,4459,3912,925,295,325,3642,2749,2189,2759,555,4349,667,1048,2694,4675,969,714,4301,251,215,4305,3114,4668,884,2303,500,4874,4466,348,834,474,2842,1634,4725,1870,4098,2213,3574,2630,3545,4993,2698,4598,4987,4449,3044,544,3417,4575,3347,2182,163,3593,69,1269,877,1817,1757,2767,867,2515,4071,297,4415,4292,2471,255,4027,227,3290,2163,4243,2099,4600,1366,3241,455,1117,1187,1151,3137,3610,3193,731,3982,629,3444,4330,1548,4035,3734,3596,4482,3963,12,4310,237,3003,1745,4853,1335,1415,2173,4676,3156,774,2015,3552,778,1076,4566,3056,3302,3529,2628,1277,3260,1186,4694,256,1068,3238,4931,1202,3779,1641,4026,1084,1464,4611,2075,72,479,3364,624,3389,4339,2810,4451,1147,2484,59,908,1461,2553,2961,4969,4476,181,2394,3246,4866,1546,4955,1542,3163,159,2453,579,2531,3204,4540,4954,2115,4696,232,3431,2755,3712,3497,2652,2660,3138,2301,3927,3619,567,2603,1451,2557,1636,3838,4162,3616,4702,36,207,2059,1059,2309,2770,228,3027,636,4956,1280,1060,1444,3727,4727,1574,1002,513,3763,413,2114,2288,44,3258,4364,2883,1610,210,287,1053,1755,715,431,2904,2357,3602,654,2209,944,286,764,4972,2600,1866,1325,2573,3177,401,1028,304,4546,3525,1085,1507,4101,955,3186,1128,4776,1540,3948,2859,675,3457,3878,3382,3037,1400,1689,306,1232,418,3026,3704,1982,4796,3178,4632,246,1364,2454,3124,1831,1537,341,1130,3461,787,3749,4934,1127,1967,2939,2788,3085,56,528,692,712,2726,1039,3830,2743,3050,429,2295,3304,4384,2813,1258,697,244,328,4532,902,4659,2523,4569,2672,1081,1267,1528,1095,4043,3108,3947,4207,4433,3923,3985,3272,2249,4891,1588,2983,2460,4335,3762,3600,1286,3504,2310,950,2610,3543,4177,364,3390,2940,2772,4203,3110,4245,345,3229,3738,4457,1191,2043,1598,3325,954,4976,3636,333,2378,2713,735,918,3151,3324,2956,1806,1047,2875,2495,145,4048,1816,4992,3365,463,2353,841,4475,2419,3348,768,4983,2817,1176,1881,1183,3956,3386,647,225,1624,1190,1631,4480,4733,3905,2849,3168,2616,1510,4473,3658,2188,3716,1150,4166,2177,3038,1753,1871,2607,2696,1341,122,4994,4467,4968,4933,610,2408,449,1023,2431,326,3680,4945,3257,2814,3434,161,3399,4932,2611,2255,967,4011,388,2206,3882,4037,223,3590,2915,3653,18,1175,3611,1779,4883,4578,2920,2852,3683,3603,4677,3284,784,4350,4715,1436,848,4900,4130,2235,2158,4726,4478,1666,1470,2562,1751,1158,2313,772,1243,4485,1750,956,3405,327,2439,2053,2341,4633,2768,4836,3941,3273,26,3789,3952,3598,2023,4345,705,2922,3851,2226,530,1850,3967,1314,1457,1925,3784,4534,3152,3514,1741,269,1890,2946,646,3721,1218,1087,1854,3528,3824,2982,1025,1380,226,1905,4186,1677,3565,1399,268,4638,289,3832,1090,3800,1416,137,397,2253,189,183,454,2019,2581,3334,2410,1447,1924,1939,4542,70,1107,3835,2951,2064,5000,4068,353,1429,1323,3954,1271,2441,1170,4020,788,687,4942,4586,2136,2215,2383,4287,2029,4347,4528,3518,2352,2931,4669,1256,1676,4981,2145,4146,119,2654,4759,205,3989,1829,365,1391,2921,4277,1131,4089,299,2137,2602,3625,1614,3583,4046,550,496,4872,4560,2069,2102,4626,3367,2058,1305,4362,1518,3169,3865,1930,3496,4596,3022,4435,239,3360,1991,1385,4822,3060,621,3008,501,3607,4442,860,4777,4657,1480,4703,1838,927,2267,4374,2042,2229,986,2668,3510,3759,1370,1114,4091,2870,3247,3686,3394,4761,3107,953,4815,4403,4318,1490,1543,2217,1633,2967,506,2001,2662,1912,2143,1586,4159,4282,1141,2250,3162,3182,493,28,4604,2434,642,4518,2146,1940,4547,63,3986,4750,3094,1873,3209,1684,25,2974,1758,2331,182,1281,1565,1957,1749,4084,4440,3837,3111,2265,4090,3575,3449,2907,209,583,2699,3512,3760,4704,2794,4354,1160,4576,2344,4145,391,4800,1024,4614,135,521,1533,4907,3863,657,2412,2959,4778,3803,4064,1824,1803,359,1756,3145,2827,2902,3040,4092,1361,586,1108,432,4311,2283,577,1438,1212,3793,1308,4793,307,2941,3259,3471,809,4538,3898,1530,3214,4555,1259,517,3904,3556,396,3135,1489,4603,298,4221,3554,1878,1425,3308,213,4302,3745,4887,4008,4417,709,4361,3371,420,2692,1938,1731,3761,42,361,4752,2326,445,3183,2033,996,4977,4427,931,4327,3996,1874,1567,2507,3768,4764,963,2336,2232,3018,4289,615,4472,854,3472,4958,2457,2119,4386,3827,2517,1859,3945,2356,845,3219,1116,199,891,444,2908,2492,1154,1322,3703,1306,755,4167,4888,2040,2366,4125,2800,3313,1070,4067,4882,3042,543,907,3570,2165,2880,665,2906,4054,1968,4628,3922,1214,1725,3402,3486,2818,3885,96,1224,4939,1664,3936,2877,7,152,2596,4735,398,1321,436,2109,511,2677,3475,3298,664,2899,3237,2972,3426,3778,725,340,3896,2751,4658,726,4378,2216,1166,2354,1848,1078,2350,1357,311,3932,3751,4273,218,1257,4281,560,1688,2308,4962,2591,1796,3483,1639,3921,901,3743,4260,1513,1034,4082,4060,4153,3116,791,3493,924,2447,1917,339,52,3872,301,1384,680,562,3861,3842,1254,3640,3781,2314,4371,2411,1880,1547,2444,4094,1851,4360,1705,3058,4988,1339,3240,1984,2011,3791,242,4244,3147,904,2824,1811,3739,656,1687,2405,294,2554,2132,605,1407,4052,3316,4165,1138,3066,2141,883,3701,4107,2196,2160,2248,4135,1621,2238,2325,179,960,3020,4513,3860,3823,3588,178,4398,4680,873,3678,600,1356,1251,679,4781,3011,3740,4191,1430,4804,4464,2488,117,2077,661,875,2565,1786,2878,1761,4985,2782,4320,4922,3395,4855,4881,2082,2631,4523,2903,4306,3374,4148,4199,1883,3319,4758,1168,363,2605,2942,2757,4957,462,949,2436,343,1317,1295,3801,151,4667,1292,4858,1476,2202,1963,4356,3808,3836,1815,1418,3886,288,1907,2475,2342,4792,3256,3691,58,1680,2971,3005,1693,899,3244,618,2724,2819,2539,3626,1030,224,1522,4688,556,3129,3711,2879,4236,3767,1428,4429,2370,717,991,2120,488,4110,862,2376,1739,2872,197,1496,4124,2273,2084,1927,4293,3433,2665,663,2259,4794,4766,3563,2047,55,4571,35,3785,195,2388,2123,4229,1067,249,1958,4746,3503,3148,3036,2526,1746,4841,2918,4896,1465,4187,4471,1420,3911,874,3605,3665,2167,4313,4108,1460,2682,3333,236,4065,4126,4492,830,360,3388,3557,1892,1413,1620,1318,3526,3534,2740,968,3586,4348,447,1671,4787,4217,3286,1065,569,603,942,4053,879,552,1747,1481,2812,3230,2299,4226,4015,480,623,1093,3059,4959,1836,1681,1877,1260,4918,2826,581,2994,2468,4660,282,1913,4231,3061,3717,1570,1573,3748,1291,1638,4535,2462,4533,4811,3560,3249,1694,4895,4038,2868,2134,3269,362,3669,3659,2172,3235,2513,2866,3532,3310,1042,4102,1844,478,522,3,3951,1974,2763,638,1253,2725,386,1828,3833,4755,4732,4157,2669,192,1697,4894,4006,4568,157,1962,1520,3722,653,168,2231,2753,2572,4208,1137,4304,405,4209,4253,3412,4164,1097,2174,4938,4621,547,2584,1362,4200,2638,1560,497,2338,626,3821,3635,4790,4689,3802,2499,4795,1119,3436,4248,3408,1371,247,641,385,2561,1484,691,2060,49,2262,1057,3972,3890,1727,1155,1125,2346,3228,1985,305,2175,2952,2030,1019,160,1696,2031,1535,977,1597,2151,4527,2676,4562,802,1417,3887,2839,2044,972,1710,4831,614,1783,580,2152,1149,1730,461,403,312,3541,4639,1337,4192,2110,3190,3520,740,578,3296,2477,1814,2318,4642,165,3052,4257,3753,794,4783,593,3351,1896,573,1241,3293,4536,4818,815,776,3744,1390,649,910,4075,994,1845,3097,3314,2709,112,180,3096,1178,971,4791,2228,551,3938,2125,816,378,4201,2958,2210,4351,3301,31,292,1839,2683,1529,2686,1722,126,2424,141,2430,121,943,1785,4462,1707,2427,284,3419,156,1363,1856,3903,3746,3143,3901};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int arrShell[n];
    for (int i = 0; i < n; i++) {
        arrShell[i] = arr[i];
    }
    
    // bubble sorting
    auto start_bubble = high_resolution_clock::now();
    bubbleSort(arr, n, swapCount_bubble);
    auto stop_bubble = high_resolution_clock::now();
    auto duration_bubble = duration_cast<microseconds>(stop_bubble - start_bubble);
    cout << "Bubble Sorted Array:\n";
    printArray(arr, n);
    cout << "Time taken by Bubble Sort: " << duration_bubble.count() << " microseconds\n";
    cout << "Bubble Sort Swaps: " << swapCount_bubble << endl;
    
    // shell sorting
    auto start_shell = high_resolution_clock::now();
    shellSort(arrShell, n, swapCount_shell);
    auto stop_shell = high_resolution_clock::now();
    auto duration_shell = duration_cast<microseconds>(stop_shell - start_shell);
    cout << "\nShell Sorted array: \n";
    printArray(arrShell, n);
    cout << "Time taken by Shell Sort: " << duration_shell.count() << " microseconds\n";
    cout << "Shell Sort Swaps: " << swapCount_shell << endl;
    cout << "\n";
    
    
    return 0;
    
}