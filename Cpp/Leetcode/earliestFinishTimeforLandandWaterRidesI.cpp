class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
      int landSize = landDuration.size();
      int waterSize = waterDuration.size();
      int earliestLandEnd = landStartTime[0]+landDuration[0];
      int earliestWaterEnd = waterStartTime[0]+waterDuration[0];
      int landWaterfjsdfkjsflsjflfsalfkja;lfja
      
      // Get minimums
      for (int i = 0; i < landSize; ++i) {
        if (landStartTime[i]+landDuration[i] < landSize) {
          landSize = landStartTime[i]+landDuration[i];
        }
      }
      for (int i = 0; i < waterSize; ++i) {
        if (waterStartTime[i]+waterDuration[i] < waterSize) {
          waterSize = waterStartTime[i]+waterDuration[i];
        }
      }

      // Get land -> water lowest time
      for (int i = 0; i < waterSize; ++i) {
        if (waterStartTime[i] >= earliestLandEnd) {

        }
      }
    }
};
