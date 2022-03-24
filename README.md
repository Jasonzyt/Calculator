# Calculator
In-game calculator for MCBDS based on [LiteLoaderBDS](https://github.com/LiteLDev/LiteLoaderBDS)

## Thanks
### Third-party Library Used
- [CMathParser](https://github.com/NTDLS/CMathParser) `LGPL-3.0`
### Submodule
- [LiteLoaderSDK(`./SDK/`)](https://github.com/LiteLDev/LiteLoaderSDK) `GPL-3.0`

## Usage
### Installation
1. Download plugin from [Releases](https://github.com/Jasonzyt/Calculator/releases)
2. Move the plugin to `[Your BDS&LL Root Dir]/plugins/` directory
3. Start the server

### Command
```
/calc
Calculate a math expression

/calc <expression: string>
/calc help

Operators:
- First Order:
    *  	Multiplication
    /  	Division
    %  	Modulation
- Second Order:
    +  	Addition
    -  	Subtraction
- Third Order:
    <> 	Logical Not Equal
    |= 	Bitwise Or Equal
    &= 	Bitwise And Equal
    ^= 	Bitwise XOR Equal
    <= 	Less or Equal
    >= 	Greater or Equal
    != 	Not Equal
    <<	Bitwise Left Shift
    >>	Bitwise Right Shift
    =  	Logical Equals
    >  	Logical Greater Than
    <  	Logical Less Than
    && 	Logical AND
    || 	Logical OR
    |  	Bitwise OR
    &  	Bitwise AND
    ^  	Exclusive OR
    !  	Logical NOT
```
