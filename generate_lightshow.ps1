$LED_COUNT = 15
$LEVEL_COUNT = 8
$DIAGONAL_COUNT = 6
$COLUMN_COUNT = 6

$EXECUTION_DEFINITION = "
typedef struct Execution {
    int bits[15];
    int numberOfExecutions;
};
"

function createBitPosition($currentIndex, [array]$turnedOnIndizes) {
    foreach ($turnedOnLed in $turnedOnIndizes) {
        if ($currentIndex -eq $turnedOnLed) {
            return "1"
        }
    }
    return "0"
}

function createBitString($turnedOnLeds) {
    $bitString = "{"
    for ($i = 0; $i -lt $LED_COUNT; $i++) {
        $nextPosition = createBitPosition -currentIndex $i -turnedOnIndizes $turnedOnLeds
        if ($i -eq ($LED_COUNT - 1)) {
            $bitString += "$nextPosition}"    
        } else {
            $bitString += "$nextPosition, "
        }
    }
    return $bitString
}

function formatExecution($rawBitString, $times) {
    return "{$rawBitString,$times},`n"
}

function appendBitString($bitSequence, $times, $turnedOn) {
    $bitString = createBitString -turnedOnLeds $turnedOn
    $bitSequence += (formatExecution $bitString $times)
    return $bitSequence
}

# led index functions
function allLedsTurnedOn() {
    $turnedOn = @()
    for ($i = 0; $i -lt $LED_COUNT; $i++) {
        $turnedOn += $i
    }
    return $turnedOn
}

function allLedsTurnedOff() {
    $turnedOn = @()
    return $turnedOn
}

function ledsColumn1() {
    return @(0, 1, 2)
}

function ledsColumn2() {
    return @(3)
}

function ledsColumn3() {
    return @(4, 5, 6)
}

function ledsColumn4() {
    return @(7)
}

function ledsColumn5() {
    return @(8, 9)
}

function ledsColumn6() {
    return @(10, 11, 12, 13, 14)
}

function ledsDiagonal1() {
    return @(0, 7)
}

function ledsDiagonal2() {
    return @(1, 8)
}

function ledsDiagonal3() {
    return @(2, 9, 10)
}

function ledsDiagonal4() {
    return @(2, 9, 10)
}

function ledsDiagonal5() {
    return @(3, 4, 5, 11, 12)
}

function ledsDiagonal6() {
    return @(6, 13, 14)
}

function ledsLevel1() {
    return @(1, 14)
}

function ledsLevel2() {
    return @(1, 13)
}

function ledsLevel3() {
    return @(2, 11, 12)
}

function ledsLevel4() {
    return @(3, 10)
}

function ledsLevel5() {
    return @(4, 9)
}

function ledsLevel6() {
    return @(5)
}

function ledsLevel7() {
    return @(6, 8)
}

function ledsLevel8() {
    return @(7)
}

function turnOnWith($indexProviderFunctionBase, $steps, $times) {
    $bitSequence = ""
    $turnedOn = @()
    for ($step = 1; $step -le $steps; $step++) {
        $turnedOn += Invoke-Expression "$indexProviderFunctionBase$step"
        $bitSequence = appendBitString $bitSequence $times $turnedOn
    }
    return $bitSequence, $steps
}

## colors
function yellowLeds() {
    return @(0, 2, 6, 8, 9, 13)
}

function blueLeds() {
    return @(1, 5, 7)
}

function redLeds() {
    return @(3, 10, 11)
}

function whiteLeds() {
    return @(4, 12)
}

function greenLeds() {
    return @(14)
}


# light show functions

function turnOnOneSequentially($times = 2) {
    $bitSequence = ""
    for ($i = 0; $i -lt $LED_COUNT; $i++) {
        $bitSequence = appendBitString $bitSequence $times @($i)
    }
    return $bitSequence, $LED_COUNT
}

function turnOnOneSequentiallyDesc($times = 2) {
    $bitSequence = ""
    for ($i = ($LED_COUNT - 1); $i -ge 0; $i--) {
        $bitSequence = appendBitString $bitSequence $times @($i)
    }
    return $bitSequence, $LED_COUNT
}

function turnOffOnlyOneSequentially($times = 2) {
    $bitSequence = ""
    for ($i = 0; $i -lt $LED_COUNT; $i++) {
        $turnedOn = allLedsTurnedOn
        $turnedOn = $turnedOn | Where-Object { $_ -ne $i }
        $bitSequence = appendBitString $bitSequence $times $turnedOn
    }
    return $bitSequence, $LED_COUNT
}

function turnOffOnlyOneSequentiallyDesc($times = 2) {
    $bitSequence = ""
    for ($i = ($LED_COUNT - 1); $i -ge 0; $i--) {
        $turnedOn = allLedsTurnedOn
        $turnedOn = $turnedOn | Where-Object { $_ -ne $i }
        $bitSequence = appendBitString $bitSequence $times $turnedOn
    }
    return $bitSequence, $LED_COUNT
}

function turnOnSequentially($times = 2) {
    $bitSequence = ""
    $turnedOn = @()
    for ($i = 0; $i -lt $LED_COUNT; $i++) {
        $turnedOn += $i
        $bitSequence = appendBitString $bitSequence $times $turnedOn
    }
    return $bitSequence, $LED_COUNT
}

function turnOnSequentiallyDesc($times = 2) {
    $bitSequence = ""
    $turnedOn = @()
    for ($i = ($LED_COUNT - 1); $i -ge 0; $i--) {
        $turnedOn += $i
        $bitSequence = appendBitString $bitSequence $times $turnedOn
    }
    return $bitSequence, $LED_COUNT
}

function turnOffSequentially($times = 2) {
    $bitSequence = ""
    $turnedOn = allLedsTurnedOn
    for ($i = 0; $i -lt $LED_COUNT; $i++) {
        $turnedOn = $turnedOn[1..$turnedOn.Length]
        $bitSequence = appendBitString $bitSequence $times $turnedOn
    }
    return $bitSequence, $LED_COUNT
}

function turnOffSequentiallyDesc($times = 2) {
    $bitSequence = ""
    $turnedOn = allLedsTurnedOn
    $bitSequence = appendBitString $bitSequence $times ($turnedOn)
    for ($i = ($LED_COUNT - 2); $i -ge 0; $i--) {
        $turnedOn = $turnedOn[0..$i]
        $bitSequence = appendBitString $bitSequence $times $turnedOn
    }

    return $bitSequence, $LED_COUNT
}

function turnOnLevelSequentially($times = 2) {
    return turnOnWith "ledsLevel" $LEVEL_COUNT $times
}

function turnOffLevelSequentially($times = 2) {
    $turnedOn = allLedsTurnedOn
    $bitSequence = appendBitString $bitSequence $times $turnedOn
    for ($level = $LEVEL_COUNT; $level -gt 0; $level--) {
        $turnedOnInLevel = Invoke-Expression "ledsLevel$level"
        $turnedOn = $turnedOn | Where-Object { !($turnedOnInLevel -contains $_) }
        $bitSequence = appendBitString $bitSequence $times $turnedOn
    }
    return $bitSequence, $LEVEL_COUNT
}

function turnOnColumnSequentially($times = 2) {
    return turnOnWith "ledsColumn" $COLUMN_COUNT $times
}

function turnOnDiagonalSequentially($times = 2) {
    return turnOnWith "ledsDiagonal" $DIAGONAL_COUNT $times
}

function diagonalSpin($spins, $times = 2) {
    $bitSequence = ""
    for ($i = 0; $i -lt $spins; $i++) {
        for ($diagonal = 1; $diagonal -le $DIAGONAL_COUNT; $diagonal++) {
            $turnedOn = Invoke-Expression "ledsDiagonal$diagonal"
            $bitSequence = appendBitString $bitSequence $times $turnedOn
        }
    }
    return $bitSequence, ($spins * $DIAGONAL_COUNT)
}

function diagonalSpinDesc($spins, $times = 2) {
    $bitSequence = ""
    for ($i = 0; $i -lt $times; $i++) {
        for ($diagonal = $DIAGONAL_COUNT; $diagonal -ge 1; $diagonal--) {
            $turnedOn = Invoke-Expression "ledsDiagonal$diagonal"
            $bitSequence = appendBitString $bitSequence $times $turnedOn
        }
    }
    return $bitSequence, ($spins * $DIAGONAL_COUNT)
}

function turnOnDiagonalSequentiallyDesc($times = 2) {
    $bitSequence = ""
    $turnedOn = @()
    for ($diagonal = $DIAGONAL_COUNT; $diagonal -ge 1; $diagonal--) {
        $turnedOn += Invoke-Expression "ledsDiagonal$diagonal"
        $bitSequence = appendBitString $bitSequence $times $turnedOn
    }
    return $bitSequence, $DIAGONAL_COUNT
}

function blink($blinks, $times = 2) {
    $bitSequence = ""
    for ($i = 0; $i -lt $blinks; $i++) {
        $bitSequence = appendBitString $bitSequence $times (allLedsTurnedOn)
        $bitSequence = appendBitString $bitSequence $times (allLedsTurnedOff)
    }
    return $bitSequence, ($blinks * 2)
}

function colorBlink($blinks, $colorIndexFunction, $times = 2) {
    $bitSequence = ""
    for ($i = 0; $i -lt $blinks; $i++) {
        $colorIndexes = Invoke-Expression "$colorIndexFunction"
        $bitSequence = appendBitString $bitSequence $times $colorIndexes
        $bitSequence = appendBitString $bitSequence $times (allLedsTurnedOff)
    }
    return $bitSequence, ($blinks * 2)
}

function addLightShowStep($lightShowStepFunction, $arg1, $arg2) {
    $sequence, $steps = Invoke-Expression "$lightShowStepFunction $arg1 $arg2"
    $global:lightShow += $sequence
    $global:totalSteps += $steps
}

# globals
$global:lightShow = ""
$global:totalSteps = 0

# generation
addLightShowStep turnOnOneSequentially
addLightShowStep turnOnSequentially
addLightShowStep turnOffOnlyOneSequentially 1
addLightShowStep turnOffOnlyOneSequentially 1
addLightShowStep turnOffSequentially
addLightShowStep turnOnOneSequentiallyDesc
addLightShowStep turnOnSequentiallyDesc
addLightShowStep turnOffOnlyOneSequentiallyDesc 1
addLightShowStep turnOffOnlyOneSequentiallyDesc 1
addLightShowStep turnOffSequentiallyDesc
addLightShowStep blink 5
addLightShowStep colorBlink 3 redLeds
addLightShowStep colorBlink 2 blueLeds
addLightShowStep colorBlink 1 redLeds
addLightShowStep colorBlink 1 yellowLeds
addLightShowStep colorBlink 2 whiteLeds
addLightShowStep turnOnLevelSequentially
addLightShowStep turnOffLevelSequentially 1
addLightShowStep turnOnColumnSequentially
addLightShowStep colorBlink 3 blueLeds
addLightShowStep colorBlink 1 greenLeds
addLightShowStep colorBlink 2 yellowLeds
addLightShowStep turnOnDiagonalSequentially
addLightShowStep diagonalSpin 3 1
addLightShowStep turnOnDiagonalSequentially 
addLightShowStep diagonalSpinDesc 3 1
addLightShowStep turnOnDiagonalSequentiallyDesc
addLightShowStep blink 3 1
addLightShowStep blink 2 2
addLightShowStep blink 1 3


$lightShow = $lightShow.TrimEnd().Substring(0, $lightShow.Length - 2)

$lightShowStepCountDefinition = "int TOTAL_STEPS=$totalSteps;`n"
$lightShowArray = "Execution LIGHT_SHOW[$totalSteps] = { `n$lightShow};"


$lightShowString = "$EXECUTION_DEFINITION`n$lightShowStepCountDefinition$lightShowArray"
Write-Host $lightShowString
New-Item -Path "lightshow.h" -Value $lightShowString -Force