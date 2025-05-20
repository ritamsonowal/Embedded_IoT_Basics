# PowerShell script to generate frames_array.h

$source_folder = "D:\IOT\Arduino UNO\18.OLED\7.Animation\Animation\C"
$output_file = "D:\IOT\Arduino UNO\18.OLED\7.Animation\Animation\frames_array.h"

# Initialize the header file with include guards
Set-Content -Path $output_file -Value "#ifndef FRAMES_ARRAY_H"
Add-Content -Path $output_file -Value "#define FRAMES_ARRAY_H"

# Start the array declaration
Add-Content -Path $output_file -Value "const tImage* frames[] = {"

# Loop through all .c files in the C directory
Get-ChildItem -Path $source_folder -Filter "*.c" | ForEach-Object {
    $file_name = $_.Name
    $frame_name = $file_name -replace ".c", ""  # Remove .c extension
    Add-Content -Path $output_file -Value "    &$frame_name,"
}

# Close the array and the header file
Add-Content -Path $output_file -Value "};"
Add-Content -Path $output_file -Value "#endif"

Write-Host "Header file generated successfully!"
