#ifndef PROBE_H
#define PROBE_H

#include <cstdint>
#include <ostream>

enum class probe_type { comparison = 0,
                        swap = 1 };

class probe {
public:
    probe() : counters{0, 0} {};

    // move constructor
    probe(probe &&o) noexcept = default;

    inline void increment(probe_type t) {
#ifdef PROBE
        counters[static_cast<int>(t)]++;
#endif
    }

    uint64_t counters[2];
};

std::ostream &operator<<(std::ostream &s, const probe &p) {
#ifdef PROBE
    s << "Comparações: " << p.counters[0] << " Trocas: " << p.counters[1] << std::endl;
#endif
    return s;
}

#endif /* PROBE_H */