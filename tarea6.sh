echo -e "\e[32mComenzaremos con la instalacion de docker i weas\e[0m"
sudo apt-get update
sudo apt-get dist-upgrade
sudo apt install apt-transport-https ca-certificates curl software-properties-common
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu bionic stable"
sudo apt update
apt-cache policy docker-ce
sudo apt install docker-ce
echo -e "\e[31mEstamos listos con la instalacion de docker YUJUUU\e[0m"
echo -e "\e[31mPara verificar que se esta ejecutando\e[0m"
echo -e "\e[31msudo systemctl status docker\e[0m"
echo -e "\e[31mfuente: https://www.digitalocean.com/community/tutorials/como-instalar-y-usar-docker-en-ubuntu-18-04-1-es\e[0m"
echo -e "\e[32mAhora es la instalacion de docker-compose i weas\e[0m"
sudo curl -L https://github.com/docker/compose/releases/download/1.21.2/docker-compose-`uname -s`-`uname -m` -o /usr/local/bin/docker-compose
sudo chmod +x /usr/local/bin/docker-compose
echo -e "\e[31mestamos listos con la instalacion de docker-compose YUJUUU\e[0m"
echo -e "\e[31mfuente: https://www.digitalocean.com/community/tutorials/how-to-install-docker-compose-on-ubuntu-18-04\e[0m"
echo -e "\e[32mAhora comprobaremos las versiones de docker y docker-compose i weas\e[0m"
docker -v
docker-compose --version
echo -e "\e[31mpara hacer al usuario parte del grupo docker ejecutar lo siguiente:\e[0m"
echo -e "\e[31msudo gpasswd -a $USER docker\e[0m"
