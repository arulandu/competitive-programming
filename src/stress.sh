# A and B are executables you want to compare, gen takes int
# as command line arg. Usage: 'sh stress.sh'
for ((i = 1; ; ++i)); do  # if they are same then will loop forever
    echo $i
    python3 gen.py $i > int;
    ./Cb < int > out1
    ./C < int > out2
    diff -w out1 out2 || break
done