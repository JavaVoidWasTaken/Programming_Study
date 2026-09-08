#include <iostream>
#include <stdint.h>

using namespace std;
using ll = int64_t;

const double largeCreepSoulGain = 5.47;
const double sacrificeCooldown = 270;

double souls = 0;
double largeCreepSouls = 506;
double sacrificeCurrentCD = 0;
double averageSPM = 0;

ll currentTime = 0;

void sacrifice() {
    souls += largeCreepSouls;
    sacrificeCurrentCD = sacrificeCooldown;
}

void tick() {
    averageSPM = souls/currentTime*60;
    cout << currentTime << " " << souls << " " << largeCreepSouls << " " << averageSPM << "\n";
    if (currentTime % 60 == 0) { largeCreepSouls += largeCreepSoulGain; }
    sacrificeCurrentCD -= 1;
    ++currentTime;
}

int main() {
    ll end;
    cin >> end;

    while (currentTime < end) {
        if (sacrificeCurrentCD == 0) { sacrifice(); }
        tick();
    }
}

