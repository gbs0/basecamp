## Born2BeRoot
This is a brief instructions of how I did the challenge using Debian and VirtualBox.

### Expand to total size paritition:
First, we need to set our user as root:
```
su -
```
Type your password, then, we need to use `lvextend` command to extend logic volumes.
```lvextend -L+200M /dev/LVMGroup/<name_of_partition> -r```

If you want to view some of the names and adresses just enter:
```vgdisplay```

Or, for shrink preview:
```lsblk```

### Reduce size of partition:
Sometimes we need to reduce our partiotion size, so just type:
```lvreduce -L-200M /dev/LVMGroup/<name> -r```

### 1 - Sudo Installation:
Switch to root and its environment via:
```
su -.
```

Install sudo via:
```
apt install sudo
```

Verify whether sudo was successfully installed typing:
```
dpkg -l | grep sudo
```

### 2 - Adding User to sudo Group
Add user to sudo group typing:
```
adduser <username> sudo
```

Verify whether user was successfully added to sudo group via:
```
getent group sudo
```

**Reboot for changes take effect.**

Log in and verify sudopowers executing
```
sudo -v
[sudo] password for <username>: <password>
```

### 2.1 - Changing hostname
In order to set a new hostname, just enter:
```
sudo hostnamectl set-hostname <username + 42>
```

Then reboot for persist changes.

### 2.2 - Adding group and assing to current user
To create a group, simple use:
```
sudo addgroup <group_name>
```

Now, we need to assign a existent user to this new group, so just type the following:
```
sudo gpasswd -a <username> <group_name>
```

### 3 - Configuring **sudo**
Configure sudo via `sudo vi /etc/sudoers.d/<filename>. <filename>` shall not end in ~ or contain . This file name represent some custom security policies for sudo.
```
sudo nano /etc/sudoers.d/<filename>
```

To limit authentication using sudo to 3 attempts (defaults to 3 anyway) in the event of an incorrect password, add below line to the file.
```
=> `Defaults        passwd_tries=3`
```
To add a custom error message in the event of an incorrect password:
```
=> `Defaults        badpass_message="<custom-error-message>"`
```

### 3.1 - Log **sudo** commands
To log all sudo commands to /var/log/sudo/<filename>:
```
sudo mkdir /var/log/sudo
```
```
<~~~>
Defaults        logfile="/var/log/sudo/<filename>"
<~~~>
```
To archive all sudo inputs & outputs to /var/log/sudo/:
```
Defaults        log_input,log_output
Defaults        iolog_dir="/var/log/sudo"
```

### 3.2 - Requiring TTY
To require TTY:
```
Defaults        requiretty
```
To set sudo paths to `/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin`:
```
Defaults        secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
```

### 4 - Installing & Configuring SSH
Install *openssh-server* via `sudo apt install openssh-server`.
```
sudo apt install openssh-server
```
Verify whether *openssh-server* was successfully installed via `dpkg -l | grep ssh`.
```
dpkg -l | grep ssh
```
Configure SSH via `sudo vi /etc/ssh/sshd_config`.
```
sudo vi /etc/ssh/sshd_config
```
To set up SSH using Port 4242, replace below line:
```
#Port 22
```
with:
```
Port 4242
```
To disable SSH login as *root* irregardless of authentication mechanism, replace below line
```
#PermitRootLogin prohibit-password
```
with:
```
PermitRootLogin no
```
Check SSH status via `sudo service ssh status`.
```
sudo service ssh status
```
>Alternatively, check SSH status via `systemctl status ssh`.
>```
>systemctl status ssh
>```

**Reboot for aply changes.**

### 5 - Installing & Config **Uncomplicated FireWall**
Install **ufw** via:
`sudo apt install ufw`

Verify whether ufw was successfully installed via dpkg -l | grep ufw.
`dpkg -l | grep ufw`

Enable Firewall via:
`sudo ufw enable`

Allow incoming connections using Port 4242 via sudo ufw allow 4242:
`sudo ufw allow 4242`

To remove a specific port rule, use:
```
sudo ufw status numbered && sudo ufw delete 8080
```

Check UFW status via sudo ufw status.
`sudo ufw status`

### 6 - Connecting to Server via SSH
SSH into your virtual machine using Port 4242 via `ssh <username>@<ip-address> -p 4242`.
```
ssh <username>@<ip-address> -p 4242
```

To find your IP Address, you can type:
```
ifconfig | grep inet
```
The IP is listed by the first value on inet key.

Terminate SSH session at any time via `logout`.
```
logout
```
>Alternatively, terminate SSH session via `exit`.
>```
> exit
>```

### 7 - Setting Up a cron Job
Configure cron as root via sudo crontab -u root -e.
`sudo crontab -u root -e`

To schedule a shell script to run every 10 minutes, replace below line 
`# m h  dom mon dow   command`
with:
`*/10 * * * * /bin/sh /root/scripts/monitoring.sh`

Check root's scheduled cron jobs via:
`sudo crontab -u root -l`

Now, we need to our custom directory to place our cron scripts:
`cd ../.. && sudo mkdir root/scripts`

Then, create the shell script for your custom actions:
`sudo touch /root/scripts/monitoring.sh`

Finally, make sure that your script has permission to be executed, running:
`chmod +x /root/scripts/monitoring.sh`

Now write the shell script with you own paramenters.

### 8 - User management - Setting Up a Strong Password Policy
• **Set a password age:**
In order to set a policy for password expiration, we need to configure this behaviour policy via `sudo vi /etc/login.defs`
`sudo nano /etc/login.defs`

• **Mandatory Requirements**
In order to set the password expiracy for every 30 days, we need to replace line 160 with:
`PASS_MAX_DAYS   30`

To set minimum number of days between password changes to 2 days:
`PASS_MIN_DAYS   2`

To send user a warning message 7 days (defaults to 7 anyway) before password expiry, keep as is
`PASS_WARN_AGE   7`

• **Password Strength**
Secondly, to set up policies in relation to password strength, install the *libpam-pwquality* package.
```
sudo apt install libpam-pwquality
```
Verify whether *libpam-pwquality* was successfully installed via:
```
dpkg -l | grep libpam-pwquality
```
Configure password strength policy via `sudo vi /etc/pam.d/common-password`, specifically the below line:
```
sudo vi /etc/pam.d/common-password
<~~~>
 password        requisite                       pam_pwquality.so retry=3
<~~~>
```
To set password minimum length to 10 characters, add below option to the above line.
```
minlen=10
```
To require password to contain at least an uppercase character and a numeric character:
```
ucredit=-1 dcredit=-1
```
To set a maximum of 3 consecutive identical characters:
```
maxrepeat=3
```
To reject the password if it contains `<username>` in some form:
```
reject_username
```
To set the number of changes required in the new password from the old password to 7:
```
difok=7
```
To implement the same policy on *root*:
```
enforce_for_root
```
Finally, it should look like the below:
```
password        requisite                       pam_pwquality.so retry=3 minlen=10 lcredit=-1 ucredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root
```

#### 9 - Create New User

#### 10 - Verify subject requirements [Mandatory]
Below are two commands for check some of the subject's requirements:

• For check OS version:
`head -n 2 /etc/os-realease`

• Check if AppArmor is loaded:
`/usr/sbin/aa-status`

• Check NetID state ports:
`ss -tunlp`

• Check UFW status and ports:
`/usr/sbin/ufw status`

### Bonus Part

#### Step 1: Installing Lighttpd
Install *lighttpd* via `sudo apt install lighttpd`.
```
sudo apt install lighttpd
```
Verify whether *lighttpd* was successfully installed via `dpkg -l | grep lighttpd`.
```
dpkg -l | grep lighttpd
```
Allow incoming connections using Port 80 via `sudo ufw allow 80`.
```
sudo ufw allow 80
```

#### Step 2: Installing & Configuring MariaDB
Install *mariadb-server* via `sudo apt install mariadb-server`.
```
sudo apt install mariadb-server
```
Verify whether *mariadb-server* was successfully installed via `dpkg -l | grep mariadb-server`.
```
dpkg -l | grep mariadb-server
```
Start interactive script to remove insecure default settings via `sudo mysql_secure_installation`.
```
sudo mysql_secure_installation
Enter current password for root (enter for none): #Just press Enter (do not confuse database root with system root)
Set root password? [Y/n] n
Remove anonymous users? [Y/n] Y
Disallow root login remotely? [Y/n] Y
Remove test database and access to it? [Y/n] Y
Reload privilege tables now? [Y/n] Y
```
Log in to the MariaDB console via `sudo mariadb`.
```
sudo mariadb
MariaDB [(none)]>
```
Create new database via `CREATE DATABASE <database-name>;`.
```
MariaDB [(none)]> CREATE DATABASE <database-name>;
```
Create new database user and grant them full privileges on the newly-created database via `GRANT ALL ON <database-name>.* TO '<username-2>'@'localhost' IDENTIFIED BY '<password-2>' WITH GRANT OPTION;`.
```
MariaDB [(none)]> GRANT ALL ON <database-name>.* TO '<username-2>'@'localhost' IDENTIFIED BY '<password-2>' WITH GRANT OPTION;
```
Flush the privileges via `FLUSH PRIVILEGES;`.
```
MariaDB [(none)]> FLUSH PRIVILEGES;
```
Exit the MariaDB shell via `exit`.
```
MariaDB [(none)]> exit
```
Verify whether database user was successfully created by logging in to the MariaDB console via `mariadb -u <username-2> -p`.
```
mariadb -u <username-2> -p
Enter password: <password-2>
MariaDB [(none)]>
```
Confirm whether database user has access to the database via `SHOW DATABASES;`.
```
MariaDB [(none)]> SHOW DATABASES;
+--------------------+
| Database           |
+--------------------+
| <database-name>    |
| information_schema |
+--------------------+
```
Exit the MariaDB shell via `exit`.
```
MariaDB [(none)]> exit
```

#### Step 3: Installing PHP
Install *php-cgi* & *php-mysql* via `sudo apt install php-cgi php-mysql`.
```
sudo apt install php-cgi php-mysql
```
Ver
sudo wget http://wordpress.org/latest.tar.gz -P /var/www/html
```ify whether *php-cgi* & *php-mysql* was successfully installed via `dpkg -l | grep php`.
```
dpkg -l | grep php
```

#### Step 4: Downloading & Configuring WordPress
Install *wget* via `sudo apt install wget`.
```
sudo apt install wget
```
Download WordPress to `/var/www/html` via:
```
sudo wget http://wordpress.org/latest.tar.gz -P /var/www/html.
```
Extract downloaded content via `sudo tar -xzvf /var/www/html/latest.tar.gz`.
```
sudo tar -xzvf /var/www/html/latest.tar.gz
```
Remove tarball via `sudo rm /var/www/html/latest.tar.gz`.
```
sudo rm /var/www/html/latest.tar.gz
```
Copy content of `/var/www/html/wordpress` to `/var/www/html` via `sudo cp -r /var/www/html/wordpress/* /var/www/html`.
```
sudo cp -r /var/www/html/wordpress/* /var/www/html
```
Remove `/var/www/html/wordpress` via `sudo rm -rf /var/www/html/wordpress`
```
sudo rm -rf /var/www/html/wordpress
```
Create WordPress configuration file from its sample via `sudo cp /var/www/html/wp-config-sample.php /var/www/html/wp-config.php`.
```
sudo cp /var/www/html/wp-config-sample.php /var/www/html/wp-config.php
```
Configure WordPress to reference previously-created MariaDB database & user via `sudo vi /var/www/html/wp-config.php`.
```
sudo vi /var/www/html/wp-config.php
```
Replace the below
```
23 define( 'DB_NAME', 'database_name_here' );^M
26 define( 'DB_USER', 'username_here' );^M
29 define( 'DB_PASSWORD', 'password_here' );^M
```
with:
```
23 define( 'DB_NAME', '<database-name>' );^M
26 define( 'DB_USER', '<username-2>' );^M
29 define( 'DB_PASSWORD', '<password-2>' );^M
```

#### Step 5: Configuring Lighttpd
Enable below modules via `sudo lighty-enable-mod fastcgi; sudo lighty-enable-mod fastcgi-php; sudo service lighttpd force-reload`.
```
sudo lighty-enable-mod fastcgi
sudo lighty-enable-mod fastcgi-php
sudo service lighttpd force-reload
```

### #3: Ngrok Tunnel Service

#### Step 1: Installing & Configuring ngrok
Install unzip and wget plugins from apt:
```
sudo apt-get install unzip wget
```
Then install **ngrok** via wget:
```
wget https://bin.equinox.io/c/bNyj1mQVY4c/ngrok-v3-stable-linux-amd64.tgz
```
Next, we need to extract it from terminal, and copy to `usr/local/bin` directory:
```
sudo tar xvzf ngrok-v3-stable-linux-amd64.tgz -C /usr/local/bin
```
Allow incoming connections using Port 80:
```
sudo ufw allow 80
```
In order for the service works properly, we need to add a valid ngrok token
```
ngrok config add-authtoken <token>
```
Now, we need a simple project for init our ngrok service, for purposes of this project I will clone a repository of my own:
```
cd /var/www/html && sudo git clone https://github.com/gbs0/me.git profile/
```
Then, start serving the following page with:
```
ngrok http 80 
```
**A link will be generated, so simple follow the https://<reference_link>/profile**
