# TscPin by The STEM Company

Provides basic control of Arduino pins

## Public functions
```
void initialize();
void setHigh();
void setLow();
bool isHigh();
bool isLow();
bool read();
void setHighWithDelays(int beforeDelay = 0, int afterDelay = 0);
void setLowWithDelays(int beforeDelay = 0, int afterDelay = 0);
void toggleSignal();
bool isDebounced(int signal);
void setDebounceDelay(int debounceDelayMillis);
```