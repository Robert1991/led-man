[CmdletBinding()]
param (
    [Parameter(Mandatory = $true)]
    $port,
    [Parameter(Mandatory = $false)]
    $baudRate = 115200,
    [Parameter(Mandatory = $false)]
    [String]
    $uploadToolPath = "C:\Users\Foo\AppData\Local\Arduino15\packages\esp8266\hardware\esp8266\3.0.2\tools\upload.py"
)

$fileSystemBinaryPath = "work\filsystem_data.bin"

$imageSize = 2072576
$blockSize = 8192
$page = 256
mklittlefs.exe -c ".\work\data\" -s $imageSize -b $blockSize -p $page $fileSystemBinaryPath

$flashAddress = "0x200000"
Invoke-Expression "$uploadToolPath --chip esp8266 --port $port --baud $baudRate write_flash $flashAddress $fileSystemBinaryPath"