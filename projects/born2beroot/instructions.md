## Born2BeRoot
This is a brief instructions of how I did the challenge using Debian and VirtualBox.

### Expand to total size paritition:
First, we need to set our user as root:
`su -`
Type your password, then, we need to use `lvextend` command to extend logic volumes.
`lvextend -L+200M /dev/LVMGroup/<name_of_partition> -r`

If you want to view some of the names and adresses just enter:
`vgdisplay`

Or, for shrink preview:
`lsblk`

### Reduce size of partition:
Sometimes we need to reduce our partiotion size, so just type:
`lvreduce -L-200M /dev/LVMGroup/<name> -r`

### 1 - Sudo Installation:
Switch to root and its environment via:
`su -.`

Install sudo via:
` apt install sudo`

Verify whether sudo was successfully installed typing:
` dpkg -l | grep sudo `

### 2 - Adding User to sudo Group
Add user to sudo group typing:
`adduser <username> sudo`

Verify whether user was successfully added to sudo group via:
`getent group sudo`

**Reboot for changes take effect.**

Log in and verify sudopowers executing
```
sudo -v
[sudo] password for <username>: <password>
```

### 3 - Configuring **sudo**
Configure sudo via `sudo vi /etc/sudoers.d/<filename>. <filename>` shall not end in ~ or contain . This file name represent some custom security policies for sudo.
`sudo nano /etc/sudoers.d/<filename>`


To limit authentication using sudo to 3 attempts (defaults to 3 anyway) in the event of an incorrect password, add below line to the file.
=> `Defaults        passwd_tries=3`

To add a custom error message in the event of an incorrect password:

=> `Defaults        badpass_message="<custom-error-message>"`


### 3.1 - Log **sudo** commands
To log all sudo commands to /var/log/sudo/<filename>:

`sudo mkdir /var/log/sudo`
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
### 4 - Installing & Config **Uncomplicated FireWall**
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

### 5 - User management - Setting Up a Strong Password Policy
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


#### X - Verify subject requirements [Mandatory]
Below are two commands for check some of the subject's requirements:

• For check OS version:
`head -n 2 /etc/os-realease`

• Check if AppArmor is loaded:
`/usr/sbin/aa-status`

• Check NetID state ports:
`ss -tunlp`

• Check UFW status and ports:
`/usr/sbin/ufw status`