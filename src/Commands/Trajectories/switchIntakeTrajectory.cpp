#include "Commands/MotionProfile.h"
namespace SwitchIntakeTrajectories
{

extern const unsigned int kTrajectoryLength = 133;

extern const robovikes::TrajectoryPoint leftTrajectories[] = {
  // { position (R), velocity (RPM) },
  { 0.155853, 3.11707 },
  { 0.713977, 5.58123 },
  { 2.11666, 14.0268 },
  { 4.61031, 24.9366 },
  { 8.50665, 38.9634 },
  { 14.1174, 56.1073 },
  { 21.7542, 76.3682 },
  { 31.7288, 99.7462 },
  { 44.3530, 126.241 },
  { 59.9383, 155.853 },
  { 78.7966, 188.583 },
  { 101.239, 224.429 },
  { 127.579, 263.392 },
  { 158.126, 305.473 },
  { 193.193, 350.670 },
  { 233.092, 398.985 },
  { 278.133, 450.417 },
  { 328.630, 504.965 },
  { 384.893, 562.631 },
  { 447.234, 623.414 },
  { 515.966, 687.314 },
  { 591.399, 754.331 },
  { 673.845, 824.465 },
  { 763.617, 897.716 },
  { 861.025, 974.084 },
  { 966.382, 1053.57 },
  { 1080.00, 1136.17 },
  { 1202.03, 1220.33 },
  { 1332.48, 1304.49 },
  { 1471.35, 1388.65 },
  { 1618.63, 1472.82 },
  { 1774.33, 1556.98 },
  { 1938.44, 1641.14 },
  { 2110.97, 1725.30 },
  { 2291.92, 1809.46 },
  { 2481.28, 1893.62 },
  { 2679.06, 1977.78 },
  { 2885.25, 2061.94 },
  { 3099.86, 2146.10 },
  { 3322.89, 2230.26 },
  { 3554.17, 2312.87 },
  { 3793.41, 2392.35 },
  { 4040.28, 2468.72 },
  { 4294.48, 2541.97 },
  { 4555.69, 2612.10 },
  { 4823.60, 2679.12 },
  { 5097.90, 2743.02 },
  { 5378.28, 2803.80 },
  { 5664.43, 2861.47 },
  { 5956.03, 2916.02 },
  { 6252.78, 2967.45 },
  { 6554.35, 3015.77 },
  { 6860.45, 3060.96 },
  { 7170.75, 3103.04 },
  { 7484.95, 3142.01 },
  { 7802.74, 3177.85 },
  { 8123.80, 3210.58 },
  { 8447.82, 3240.19 },
  { 8774.49, 3266.69 },
  { 9103.49, 3290.07 },
  { 9434.53, 3310.33 },
  { 9767.27, 3327.47 },
  { 10101.4, 3341.50 },
  { 10436.7, 3352.41 },
  { 10772.7, 3360.20 },
  { 11109.1, 3364.40 },
  { 11445.5, 3363.43 },
  { 11781.2, 3357.80 },
  { 12116.2, 3349.04 },
  { 12449.9, 3337.17 },
  { 12782.1, 3322.18 },
  { 13112.5, 3304.08 },
  { 13440.8, 3282.86 },
  { 13766.6, 3258.52 },
  { 14089.7, 3231.06 },
  { 14409.8, 3200.49 },
  { 14726.5, 3166.80 },
  { 15039.5, 3129.99 },
  { 15348.5, 3090.06 },
  { 15653.2, 3047.02 },
  { 15953.3, 3000.86 },
  { 16248.4, 2951.59 },
  { 16538.3, 2899.19 },
  { 16822.7, 2843.68 },
  { 17101.2, 2785.05 },
  { 17373.5, 2723.31 },
  { 17639.4, 2658.45 },
  { 17898.4, 2590.47 },
  { 18150.4, 2519.37 },
  { 18394.9, 2445.16 },
  { 18631.7, 2367.83 },
  { 18860.4, 2287.39 },
  { 19080.8, 2204.30 },
  { 19292.9, 2120.14 },
  { 19496.5, 2035.98 },
  { 19691.6, 1951.82 },
  { 19878.4, 1867.66 },
  { 20056.7, 1783.50 },
  { 20226.7, 1699.34 },
  { 20388.2, 1615.18 },
  { 20541.3, 1531.02 },
  { 20686.0, 1446.85 },
  { 20822.3, 1362.69 },
  { 20950.1, 1278.53 },
  { 21069.5, 1194.37 },
  { 21180.6, 1110.69 },
  { 21283.5, 1029.05 },
  { 21378.6, 950.527 },
  { 21466.1, 875.120 },
  { 21546.4, 802.831 },
  { 21619.7, 733.658 },
  { 21686.5, 667.603 },
  { 21747.0, 604.664 },
  { 21801.4, 544.843 },
  { 21850.3, 488.139 },
  { 21893.7, 434.551 },
  { 21932.1, 384.081 },
  { 21965.8, 336.728 },
  { 21995.0, 292.492 },
  { 22020.2, 251.373 },
  { 22041.5, 213.371 },
  { 22059.4, 178.487 },
  { 22074.0, 146.719 },
  { 22085.8, 118.068 },
  { 22095.1, 92.5348 },
  { 22102.1, 70.1183 },
  { 22107.2, 50.8188 },
  { 22110.7, 34.6365 },
  { 22112.8, 21.5712 },
  { 22114.0, 11.6230 },
  { 22114.5, 4.79184 },
  { 22114.6, 1.07777 },
  { 22114.6, 0.00000 }
};
extern const robovikes::TrajectoryPoint rightTrajectories[] = {
  // { position (R), velocity (RPM) },
  { 0.155853, 3.11707 },
  { 0.713977, 5.58123 },
  { 2.11666, 14.0268 },
  { 4.61031, 24.9366 },
  { 8.50665, 38.9634 },
  { 14.1174, 56.1073 },
  { 21.7542, 76.3682 },
  { 31.7288, 99.7462 },
  { 44.3530, 126.241 },
  { 59.9383, 155.853 },
  { 78.7966, 188.583 },
  { 101.239, 224.429 },
  { 127.579, 263.392 },
  { 158.126, 305.473 },
  { 193.193, 350.670 },
  { 233.092, 398.985 },
  { 278.133, 450.417 },
  { 328.630, 504.965 },
  { 384.893, 562.631 },
  { 447.234, 623.414 },
  { 515.966, 687.314 },
  { 591.399, 754.331 },
  { 673.845, 824.465 },
  { 763.617, 897.716 },
  { 861.025, 974.084 },
  { 966.382, 1053.57 },
  { 1080.00, 1136.17 },
  { 1202.03, 1220.33 },
  { 1332.48, 1304.49 },
  { 1471.35, 1388.65 },
  { 1618.63, 1472.82 },
  { 1774.33, 1556.98 },
  { 1938.44, 1641.14 },
  { 2110.97, 1725.30 },
  { 2291.92, 1809.46 },
  { 2481.28, 1893.62 },
  { 2679.06, 1977.78 },
  { 2885.25, 2061.94 },
  { 3099.86, 2146.10 },
  { 3322.89, 2230.26 },
  { 3554.17, 2312.87 },
  { 3793.41, 2392.35 },
  { 4040.28, 2468.72 },
  { 4294.48, 2541.97 },
  { 4555.69, 2612.10 },
  { 4823.60, 2679.12 },
  { 5097.90, 2743.02 },
  { 5378.28, 2803.80 },
  { 5664.43, 2861.47 },
  { 5956.03, 2916.02 },
  { 6252.78, 2967.45 },
  { 6554.35, 3015.77 },
  { 6860.45, 3060.96 },
  { 7170.75, 3103.04 },
  { 7484.95, 3142.01 },
  { 7802.74, 3177.85 },
  { 8123.80, 3210.58 },
  { 8447.82, 3240.19 },
  { 8774.49, 3266.69 },
  { 9103.49, 3290.07 },
  { 9434.53, 3310.33 },
  { 9767.27, 3327.47 },
  { 10101.4, 3341.50 },
  { 10436.7, 3352.41 },
  { 10772.7, 3360.20 },
  { 11109.1, 3364.40 },
  { 11445.5, 3363.43 },
  { 11781.2, 3357.80 },
  { 12116.2, 3349.04 },
  { 12449.9, 3337.17 },
  { 12782.1, 3322.18 },
  { 13112.5, 3304.08 },
  { 13440.8, 3282.86 },
  { 13766.6, 3258.52 },
  { 14089.7, 3231.06 },
  { 14409.8, 3200.49 },
  { 14726.5, 3166.80 },
  { 15039.5, 3129.99 },
  { 15348.5, 3090.06 },
  { 15653.2, 3047.02 },
  { 15953.3, 3000.86 },
  { 16248.4, 2951.59 },
  { 16538.3, 2899.19 },
  { 16822.7, 2843.68 },
  { 17101.2, 2785.05 },
  { 17373.5, 2723.31 },
  { 17639.4, 2658.45 },
  { 17898.4, 2590.47 },
  { 18150.4, 2519.37 },
  { 18394.9, 2445.16 },
  { 18631.7, 2367.83 },
  { 18860.4, 2287.39 },
  { 19080.8, 2204.30 },
  { 19292.9, 2120.14 },
  { 19496.5, 2035.98 },
  { 19691.6, 1951.82 },
  { 19878.4, 1867.66 },
  { 20056.7, 1783.50 },
  { 20226.7, 1699.34 },
  { 20388.2, 1615.18 },
  { 20541.3, 1531.02 },
  { 20686.0, 1446.85 },
  { 20822.3, 1362.69 },
  { 20950.1, 1278.53 },
  { 21069.5, 1194.37 },
  { 21180.6, 1110.69 },
  { 21283.5, 1029.05 },
  { 21378.6, 950.527 },
  { 21466.1, 875.120 },
  { 21546.4, 802.831 },
  { 21619.7, 733.658 },
  { 21686.5, 667.603 },
  { 21747.0, 604.664 },
  { 21801.4, 544.843 },
  { 21850.3, 488.139 },
  { 21893.7, 434.551 },
  { 21932.1, 384.081 },
  { 21965.8, 336.728 },
  { 21995.0, 292.492 },
  { 22020.2, 251.373 },
  { 22041.5, 213.371 },
  { 22059.4, 178.487 },
  { 22074.0, 146.719 },
  { 22085.8, 118.068 },
  { 22095.1, 92.5348 },
  { 22102.1, 70.1183 },
  { 22107.2, 50.8188 },
  { 22110.7, 34.6365 },
  { 22112.8, 21.5712 },
  { 22114.0, 11.6230 },
  { 22114.5, 4.79184 },
  { 22114.6, 1.07777 },
  { 22114.6, 0.00000 }
};

} // namespace SwitchIntakeTrajectories
