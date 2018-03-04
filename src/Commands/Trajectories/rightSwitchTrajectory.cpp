#include "Commands/MotionProfile.h"
namespace RightSwitchTrajectories
{

extern const unsigned int kTrajectoryLength = 179;

extern const robovikes::TrajectoryPoint leftTrajectories[] = {
  // { position (R), velocity (RPM) },
  { 0.158261, 3.16522 },
  { 0.612472, 4.54211 },
  { 2.51739, 19.0491 },
  { 5.90410, 33.8671 },
  { 11.1963, 52.9224 },
  { 18.8183, 76.2191 },
  { 29.1946, 103.763 },
  { 42.7509, 135.563 },
  { 59.9139, 171.630 },
  { 81.1117, 211.978 },
  { 106.774, 256.626 },
  { 137.334, 305.595 },
  { 173.225, 358.913 },
  { 214.886, 416.610 },
  { 262.759, 478.725 },
  { 317.289, 545.300 },
  { 378.927, 616.385 },
  { 448.131, 692.037 },
  { 525.363, 772.321 },
  { 611.094, 857.311 },
  { 705.803, 947.088 },
  { 809.977, 1041.74 },
  { 924.116, 1141.38 },
  { 1048.73, 1246.12 },
  { 1184.34, 1356.08 },
  { 1331.48, 1471.40 },
  { 1490.70, 1592.23 },
  { 1662.35, 1716.54 },
  { 1846.58, 1842.28 },
  { 2043.53, 1969.54 },
  { 2253.38, 2098.44 },
  { 2476.29, 2229.08 },
  { 2712.44, 2361.57 },
  { 2962.04, 2496.00 },
  { 3225.29, 2632.46 },
  { 3502.39, 2771.01 },
  { 3793.56, 2911.70 },
  { 4099.02, 3054.56 },
  { 4418.97, 3199.57 },
  { 4753.64, 3346.67 },
  { 5103.22, 3495.77 },
  { 5467.89, 3646.69 },
  { 5847.80, 3799.18 },
  { 6243.10, 3952.93 },
  { 6653.85, 4107.50 },
  { 7080.08, 4262.35 },
  { 7521.77, 4416.85 },
  { 7978.79, 4570.21 },
  { 8450.94, 4721.55 },
  { 8937.93, 4869.89 },
  { 9439.10, 5011.67 },
  { 9953.43, 5143.28 },
  { 10479.8, 5263.59 },
  { 11016.9, 5371.61 },
  { 11563.6, 5466.47 },
  { 12118.3, 5547.54 },
  { 12679.8, 5614.43 },
  { 13246.5, 5667.06 },
  { 13817.1, 5705.61 },
  { 14390.1, 5730.55 },
  { 14964.4, 5742.61 },
  { 15538.6, 5742.70 },
  { 16111.8, 5731.90 },
  { 16683.0, 5711.36 },
  { 17251.2, 5682.26 },
  { 17815.8, 5645.76 },
  { 18376.1, 5602.98 },
  { 18931.6, 5554.92 },
  { 19481.8, 5502.49 },
  { 20026.5, 5446.45 },
  { 20565.2, 5387.48 },
  { 21097.8, 5326.11 },
  { 21624.1, 5262.75 },
  { 22143.9, 5197.75 },
  { 22657.0, 5131.34 },
  { 23163.4, 5063.68 },
  { 23662.9, 4994.87 },
  { 24155.5, 4926.78 },
  { 24641.6, 4861.12 },
  { 25121.4, 4797.68 },
  { 25595.0, 4736.25 },
  { 26062.7, 4676.62 },
  { 26524.6, 4618.57 },
  { 26980.7, 4561.88 },
  { 27431.4, 4506.34 },
  { 27876.5, 4451.72 },
  { 28316.3, 4397.82 },
  { 28750.8, 4344.42 },
  { 29179.9, 4291.30 },
  { 29603.7, 4238.25 },
  { 30022.2, 4185.07 },
  { 30435.4, 4131.53 },
  { 30843.1, 4077.43 },
  { 31245.4, 4022.54 },
  { 31642.1, 3966.67 },
  { 32033.0, 3909.57 },
  { 32418.1, 3851.05 },
  { 32797.2, 3790.88 },
  { 33170.1, 3728.84 },
  { 33536.6, 3664.72 },
  { 33896.4, 3598.31 },
  { 34249.3, 3529.02 },
  { 34594.8, 3455.42 },
  { 34932.5, 3376.66 },
  { 35261.8, 3292.87 },
  { 35582.2, 3204.22 },
  { 35893.3, 3110.98 },
  { 36194.7, 3013.51 },
  { 36485.9, 2912.26 },
  { 36766.7, 2807.82 },
  { 37036.7, 2700.87 },
  { 37296.0, 2592.24 },
  { 37544.3, 2482.85 },
  { 37781.6, 2373.76 },
  { 38008.2, 2266.10 },
  { 38224.3, 2161.02 },
  { 38430.3, 2059.72 },
  { 38626.7, 1963.34 },
  { 38813.9, 1872.89 },
  { 38992.9, 1789.25 },
  { 39164.2, 1713.05 },
  { 39328.6, 1644.69 },
  { 39487.1, 1584.28 },
  { 39640.2, 1531.62 },
  { 39788.9, 1486.25 },
  { 39933.6, 1447.45 },
  { 40075.0, 1414.33 },
  { 40213.6, 1385.83 },
  { 40349.7, 1361.03 },
  { 40483.7, 1339.50 },
  { 40615.7, 1320.66 },
  { 40746.1, 1303.55 },
  { 40874.8, 1287.32 },
  { 41001.9, 1271.23 },
  { 41127.4, 1254.68 },
  { 41251.1, 1237.17 },
  { 41373.0, 1218.29 },
  { 41492.7, 1197.75 },
  { 41610.3, 1175.33 },
  { 41725.4, 1150.87 },
  { 41837.8, 1124.30 },
  { 41947.3, 1095.57 },
  { 42053.8, 1064.68 },
  { 42157.0, 1031.65 },
  { 42256.6, 996.555 },
  { 42352.6, 959.458 },
  { 42444.6, 920.447 },
  { 42532.6, 879.620 },
  { 42616.3, 837.082 },
  { 42695.6, 792.938 },
  { 42770.3, 747.300 },
  { 42840.4, 700.587 },
  { 42905.8, 653.911 },
  { 42966.6, 608.101 },
  { 43022.9, 563.304 },
  { 43074.9, 519.655 },
  { 43122.6, 477.276 },
  { 43166.2, 436.278 },
  { 43205.9, 396.760 },
  { 43241.8, 358.811 },
  { 43274.0, 322.511 },
  { 43302.8, 287.930 },
  { 43328.3, 255.130 },
  { 43350.8, 224.167 },
  { 43370.3, 195.087 },
  { 43387.1, 167.933 },
  { 43401.3, 142.739 },
  { 43413.3, 119.537 },
  { 43423.1, 98.3498 },
  { 43431.0, 79.1999 },
  { 43437.3, 62.1036 },
  { 43442.0, 47.0744 },
  { 43445.4, 34.1226 },
  { 43447.7, 23.2557 },
  { 43449.1, 14.4793 },
  { 43449.9, 7.79669 },
  { 43450.2, 3.21008 },
  { 43450.3, 0.720487 },
  { 43450.3, 0.00000 }
};
extern const robovikes::TrajectoryPoint rightTrajectories[] = {
  // { position (R), velocity (RPM) },
  { 0.158261, 3.16522 },
  { 0.185349, 0.270881 },
  { 1.12913, 9.43780 },
  { 2.80677, 16.7764 },
  { 5.42757, 26.2080 },
  { 9.20045, 37.7288 },
  { 14.3337, 51.3325 },
  { 21.0348, 67.0109 },
  { 29.5101, 84.7527 },
  { 39.9644, 104.544 },
  { 52.6010, 126.365 },
  { 67.6206, 150.196 },
  { 85.2215, 176.009 },
  { 105.599, 203.772 },
  { 128.944, 233.449 },
  { 155.443, 264.996 },
  { 185.279, 298.363 },
  { 218.629, 333.493 },
  { 255.661, 370.322 },
  { 296.539, 408.776 },
  { 341.416, 448.772 },
  { 390.438, 490.220 },
  { 443.739, 533.015 },
  { 501.444, 577.044 },
  { 563.662, 622.180 },
  { 630.490, 668.286 },
  { 702.011, 715.210 },
  { 778.193, 761.817 },
  { 858.893, 807.005 },
  { 943.960, 850.664 },
  { 1033.23, 892.684 },
  { 1126.52, 932.959 },
  { 1223.66, 971.387 },
  { 1324.45, 1007.87 },
  { 1428.68, 1042.33 },
  { 1536.15, 1074.70 },
  { 1646.65, 1104.92 },
  { 1759.94, 1132.98 },
  { 1875.83, 1158.89 },
  { 1994.10, 1182.70 },
  { 2114.56, 1204.51 },
  { 2237.01, 1224.51 },
  { 2361.30, 1242.92 },
  { 2487.31, 1260.08 },
  { 2614.95, 1276.42 },
  { 2744.20, 1292.47 },
  { 2875.08, 1308.89 },
  { 3007.73, 1326.43 },
  { 3142.33, 1345.99 },
  { 3279.18, 1368.55 },
  { 3418.63, 1394.51 },
  { 3561.06, 1424.31 },
  { 3706.97, 1459.07 },
  { 3856.95, 1499.80 },
  { 4011.69, 1547.36 },
  { 4171.92, 1602.39 },
  { 4338.45, 1665.26 },
  { 4512.06, 1736.08 },
  { 4693.52, 1814.64 },
  { 4883.57, 1900.49 },
  { 5082.86, 1992.89 },
  { 5291.95, 2090.93 },
  { 5511.31, 2193.54 },
  { 5741.26, 2299.56 },
  { 5982.04, 2407.81 },
  { 6233.76, 2517.12 },
  { 6496.39, 2626.39 },
  { 6769.85, 2734.61 },
  { 7053.94, 2840.87 },
  { 7348.38, 2944.40 },
  { 7652.84, 3044.54 },
  { 7966.91, 3140.74 },
  { 8290.17, 3232.60 },
  { 8622.15, 3319.77 },
  { 8962.35, 3402.02 },
  { 9310.27, 3479.19 },
  { 9665.39, 3551.17 },
  { 10027.3, 3619.27 },
  { 10395.8, 3684.94 },
  { 10770.6, 3748.39 },
  { 11151.6, 3809.82 },
  { 11538.6, 3869.46 },
  { 11931.3, 3927.51 },
  { 12329.7, 3984.20 },
  { 12733.7, 4039.75 },
  { 13143.2, 4094.36 },
  { 13558.0, 4148.27 },
  { 13978.1, 4201.67 },
  { 14403.6, 4254.79 },
  { 14834.4, 4307.84 },
  { 15270.5, 4361.02 },
  { 15712.0, 4414.56 },
  { 16158.8, 4468.66 },
  { 16611.2, 4523.54 },
  { 17069.1, 4579.42 },
  { 17532.8, 4636.51 },
  { 18002.3, 4695.02 },
  { 18477.8, 4755.19 },
  { 18959.5, 4817.23 },
  { 19447.7, 4881.34 },
  { 19942.4, 4947.74 },
  { 20444.0, 5016.03 },
  { 20952.5, 5084.47 },
  { 21467.7, 5151.74 },
  { 21989.4, 5217.72 },
  { 22517.7, 5282.22 },
  { 23052.1, 5344.97 },
  { 23592.7, 5405.63 },
  { 24139.1, 5463.73 },
  { 24691.0, 5518.69 },
  { 25247.9, 5569.83 },
  { 25809.6, 5616.32 },
  { 26375.3, 5657.24 },
  { 26944.4, 5691.53 },
  { 27516.3, 5718.07 },
  { 28089.8, 5735.68 },
  { 28664.1, 5743.19 },
  { 29238.1, 5739.47 },
  { 29810.4, 5723.47 },
  { 30379.9, 5694.35 },
  { 30945.0, 5651.45 },
  { 31504.5, 5594.39 },
  { 32056.8, 5523.05 },
  { 32600.5, 5437.64 },
  { 33134.4, 5338.61 },
  { 33657.1, 5226.67 },
  { 34167.3, 5102.73 },
  { 34664.1, 4967.85 },
  { 35146.5, 4823.92 },
  { 35614.0, 4674.54 },
  { 36066.2, 4522.48 },
  { 36503.1, 4368.69 },
  { 36924.5, 4214.02 },
  { 37330.4, 4059.20 },
  { 37720.9, 3904.84 },
  { 38096.0, 3751.45 },
  { 38456.0, 3599.41 },
  { 38800.9, 3449.04 },
  { 39130.9, 3300.55 },
  { 39446.3, 3154.09 },
  { 39747.3, 3009.75 },
  { 40034.1, 2867.57 },
  { 40306.8, 2727.54 },
  { 40565.8, 2589.65 },
  { 40811.2, 2453.83 },
  { 41043.2, 2320.01 },
  { 41262.0, 2188.10 },
  { 41467.8, 2058.01 },
  { 41660.7, 1929.62 },
  { 41841.0, 1802.85 },
  { 42008.8, 1677.56 },
  { 42164.2, 1554.35 },
  { 42307.7, 1435.25 },
  { 42439.9, 1321.62 },
  { 42561.2, 1213.30 },
  { 42672.2, 1110.16 },
  { 42773.5, 1012.09 },
  { 42865.4, 918.966 },
  { 42948.4, 830.691 },
  { 43023.1, 747.178 },
  { 43090.0, 668.347 },
  { 43149.4, 594.127 },
  { 43201.8, 524.456 },
  { 43247.8, 459.279 },
  { 43287.6, 398.548 },
  { 43321.8, 342.223 },
  { 43350.9, 290.267 },
  { 43375.1, 242.651 },
  { 43395.1, 199.350 },
  { 43411.1, 160.342 },
  { 43423.7, 125.611 },
  { 43433.2, 95.1428 },
  { 43440.1, 68.9281 },
  { 43444.8, 46.9589 },
  { 43447.7, 29.2297 },
  { 43449.3, 15.7370 },
  { 43449.9, 6.47883 },
  { 43450.1, 1.45410 },
  { 43450.1, 0.00000 }
};

} // namespace RightSwitchTrajectories
