#include <cstdint>
#include <vector>
#include <map>
#include <string>
#include <Vector3.h>


enum class MapChipType{
 kBlank,
 kBlock,
};

struct MapChipDate
{
	std::vector<std::vector<MapChipType>>data;
};


class MapChipField{
	
	//1ブロックのサイズ
	static inline const float kBlockWidth = 1.0f;
	static inline const float kBlockHeight = 1.0f;
	//ブロックの個数
	static inline const uint32_t kNumBlockVirtical = 2;
	static inline const uint32_t kNumBlockHorizontal = 100;

	MapChipDate mapChipData_;
public:
	uint32_t GetNumBlockVirtical() const { return kNumBlockVirtical; }
	uint32_t GetNumBlockHorizontal() const { return kNumBlockHorizontal; }
	void ResetMapChipData();
	void LoadMapChipCsv(const std::string& filePath);
	MapChipType GetMapChipTypeByIndex(uint32_t xIndex, uint32_t yIndex);
	Vector3 GetMapChipPositionByIndex(uint32_t xIndex, uint32_t yIndex);
};
