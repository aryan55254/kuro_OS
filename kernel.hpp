#pragma once

// this basically mirrors the two retunr registers we wll get from opensbi after it is booted for al functins we tell it to perform by our os kuro

struct sbiret
{
    long error; // error code returned by SBI
    long value; // value returned by SBI Call
};