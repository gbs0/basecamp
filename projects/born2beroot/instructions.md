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
$ sudo vi /etc/ssh/sshd_config
```
To set up SSH using Port 4242, replace below line:
```
13 #Port 22
```
with:
```
13 Port 4242
```
To disable SSH login as *root* irregardless of authentication mechanism, replace below line
```
32 #PermitRootLogin prohibit-password
```
with:
```
32 PermitRootLogin no
```
Check SSH status via `sudo service ssh status`.
```
$ sudo service ssh status
```
>Alternatively, check SSH status via `systemctl status ssh`.
>```
>$ systemctl status ssh
>```

### 5 - Installing & Config **Uncomplicated FireWall**
Install **ufw** via:
`sudo apt install ufw`

Verify whether ufw was successfully installed via dpkg -l | grep ufw.
`dpkg -l | grep ufw`

Enable Firewall via:
`sudo ufw enable`

Allow incoming connections using Port 4242 via sudo ufw allow 4242:
`sudo ufw allow 4242`

Check UFW status via sudo ufw status.
`sudo ufw status`

### 6 - Setting Up a cron Job
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

### 7 - User management - Setting Up a Strong Password Policy
• **Set a password age:**
In order to set a policy for password expiration, we need to configure this behaviour policy via `sudo vi /etc/login.defs`
`sudo nano /etc/login.defs`

**Mandatory Requirements**
• In order to set the password expiracy for every 30 days, we need to replace line 160 with:
`PASS_MAX_DAYS   30`

• To set minimum number of days between password changes to 2 days:
`PASS_MIN_DAYS   2`

• To send user a warning message 7 days (defaults to 7 anyway) before password expiry, keep as is
`PASS_WARN_AGE   7`


#### 8 - Verify subject requirements [Mandatory]
Below are two commands for check some of the subject's requirements:

• For check OS version:
`head -n 2 /etc/os-realease`

• Check if AppArmor is loaded:
`/usr/sbin/aa-status`

• Check NetID state ports:
`ss -tunlp`

• Check UFW status and ports:
`/usr/sbin/ufw status`