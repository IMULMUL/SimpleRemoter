#pragma once

#include <vector>
#include <cstdint>
#include <string>

// Encode for IP and Port.
// provided by ChatGPT.
class StreamCipher {
private:
	uint32_t state;

	// �򵥷�����α�����������
	uint8_t prngNext() {
		// ���ӣ�xorshift32������һ�������
		state ^= (state << 13);
		state ^= (state >> 17);
		state ^= (state << 5);
		// �ٻ��һ���򵥵ķ����Ա任
		uint8_t out = (state & 0xFF) ^ ((state >> 8) & 0xFF);
		return out;
	}

public:
	StreamCipher(uint32_t key) : state(key) {}

	// ���ܽ��ܣ��Գƣ����Ȳ��䣩
	void process(uint8_t* data, size_t len) {
		for (size_t i = 0; i < len; ++i) {
			data[i] ^= prngNext();
		}
	}
};
