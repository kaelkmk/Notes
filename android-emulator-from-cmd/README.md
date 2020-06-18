# Staring Android Emulator From Cmd

## Prerequisite

Android Sdk need to be installed, <br/>

## 1. Check your android virtual device ( avd ) 
It should be shown something like this
```cmd
C:\Users\Khaing Myel Khant>emulator -list-avds
Pixel_3a_API_30_x86

C:\Users\Khaing Myel Khant>
```

### If you run this default, this error will be shown
```cmd
C:\Users\Khaing Myel Khant>emulator @Pixel_3a_API_30_x86
PANIC: Missing emulator engine program for 'x86' CPU.
```

### What Happended
Actually, the use of emulator command in Android/Sdk/tools/emulator.exe is depreciated and obsolete. <br/>

## Solution
Android Emulator Location is changed from Android/Sdk/tools/emulator.exe to Sdk/emulator/emulator.exe <br/>

We need to use the emulator.exe from Android/Sdk/emulator/emulator.exe <br/>

<div style="align:center"> ![solved](images/emulator-solved.png) </div>
