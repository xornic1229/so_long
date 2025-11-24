rm -f ./.system/a.out
sleep 0.25
sync
sleep 0.25
make clean
bash -c "$(curl https://grademe.fr)"
