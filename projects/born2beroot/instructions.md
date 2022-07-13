### Born2BeRoot
> This is a brief instructions of how I did the challenge using Debian and Virtual Machines.

#### Expand to total size paritition:
First, we need to set our user as root:
`su -`
Type your password, then, we need to use `lvextend` command to extend logic volumes.
`lvextend -L+200M /dev/LVMGroup/<name_of_partition> -r`

If you want to view some of the names and adresses just enter:
`vgdisplay`

Or, for shrink preview:
`lsblk`

#### Reduce size of partition:
Sometimes we need to reduce our partiotion size, so just type:
`lvreduce -L-200M /dev/LVMGroup/<name> -r`

#### 1 - Sudo Installation:
Switch to root and its environment via:
`su -.`

Install sudo via:
` apt install sudo`

Verify whether sudo was successfully installed typing:
` dpkg -l | grep sudo `

#### 2 - Adding User to sudo Group
Add user to sudo group typing:
`adduser <username> sudo`

Verify whether user was successfully added to sudo group via:
`getent group sudo`

* Reboot for changes take effect.

Log in and verify sudopowers executing
```
sudo -v
[sudo] password for <username>: <password>
```

#### 3 - Configuring sudo
Configure sudo via `sudo vi /etc/sudoers.d/<filename>. <filename>` shall not end in ~ or contain .
`sudo nano /etc/sudoers.d/<filename>`

To limit authentication using sudo to 3 attempts (defaults to 3 anyway) in the event of an incorrect password, add below line to the file.

• `Defaults        passwd_tries=3`

To add a custom error message in the event of an incorrect password:

• `Defaults        badpass_message="<custom-error-message>"`




