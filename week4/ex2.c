#include <stdio.h>
#include <stdlib.h>
#define N 5
int main(int argc, char *argv[])
{
    for(int i=0;i<N;i++){
        fork();
    }
    sleep(5);
    return 0;
}
/*The program create 5 (or 3 if N=3) process and each of them sleep 5 sec and the exit.
Let's consentrate on following part of processig tree for 3 process:  
--bash-+-2*[cat]
       |-ex2.out-+-ex2.out{1}-+-ex2.out---ex2.out  //The most left ex2.out is our first process
       |         |         `-ex2.out
       |         |-ex2.out{2}---ex2.out
       |         `-ex2.out{3}
       `-pstree									//here we call pstree to drow this tree
The new process continuous execution. Thus when we create first process{1}, it continuous 
execution when i=1 and it will create 2 process. There for if i=1 then process will need to create
3-2=1 process and 3-3=0 process for {3} if i=2. The same thing hapened at next stages.
If we will consider N=5 we will see the same picture:
 +-bash-+-2*[cat]
 |      |-ex22.out-+-ex22.out-+-ex22.out-+-ex22.out-+-ex22.out---ex22+
 |      |          |          |          |          `-ex22.out
 |      |          |          |          |-ex22.out---ex22.out
 |      |          |          |          `-ex22.out
 |      |          |          |-ex22.out-+-ex22.out---ex22.out
 |      |          |          |          `-ex22.out
 |      |          |          |-ex22.out---ex22.out
 |      |          |          `-ex22.out
 |      |          |-ex22.out-+-ex22.out-+-ex22.out---ex22.out
 |      |          |          |          `-ex22.out
 |      |          |          |-ex22.out---ex22.out
 |      |          |          `-ex22.out
 |      |          |-ex22.out-+-ex22.out---ex22.out
 |      |          |          `-ex22.out
 |      |          |-ex22.out---ex22.out
 |      |          `-ex22.out
 ..      `-pstree
 
Full picture for i=5
systemd-+-ModemManager-+-{gdbus}
        |              `-{gmain}
        |-NetworkManager-+-dhclient
        |                |-dnsmasq
        |                |-{gdbus}
        |                `-{gmain}
        |-VBoxClient---VBoxClient---{SHCLIP}
        |-VBoxClient---VBoxClient
        |-VBoxClient---VBoxClient---{X11 events}
        |-VBoxClient---VBoxClient-+-{dndHGCM}
        |                         `-{dndX11}
        |-VBoxService-+-{automount}
        |             |-{control}
        |             |-{cpuhotplug}
        |             |-{memballoon}
        |             |-{timesync}
        |             |-{vminfo}
        |             `-{vmstats}
        |-accounts-daemon-+-{gdbus}
        |                 `-{gmain}
        |-agetty
        |-cron
        |-2*[dbus-daemon]
        |-dbus-launch
        |-dconf-service-+-{gdbus}
        |               `-{gmain}
        |-evinced-+-{gdbus}
        |         `-{gmain}
        |-gvfs-afc-volume-+-{gdbus}
        |                 |-{gmain}
        |                 `-{gvfs-afc-volume}
        |-gvfs-goa-volume-+-{gdbus}
        |                 `-{gmain}
        |-gvfs-gphoto2-vo-+-{gdbus}
        |                 `-{gmain}
        |-gvfs-mtp-volume-+-{gdbus}
        |                 `-{gmain}
        |-gvfs-udisks2-vo-+-{gdbus}
        |                 `-{gmain}
        |-gvfsd-+-{gdbus}
        |       `-{gmain}
        |-gvfsd-fuse-+-{gdbus}
        |            |-{gmain}
        |            |-{gvfs-fuse-sub}
        |            `-2*[{gvfsd-fuse}]
        |-gvfsd-metadata-+-{gdbus}
        |                `-{gmain}
        |-gvfsd-trash-+-{gdbus}
        |             `-{gmain}
        |-indicator-appli-+-{gdbus}
        |                 `-{gmain}
        |-indicator-sound-+-{dconf worker}
        |                 |-{gdbus}
        |                 `-{gmain}
        |-light-locker-+-{dconf worker}
        |              |-{gdbus}
        |              `-{gmain}
        |-lightdm-+-Xorg---{InputThread}
        |         |-lightdm-+-lxsession-+-lxpanel-+-{dconf worker}
        |         |         |           |         |-{gdbus}
        |         |         |           |         |-{gmain}
        |         |         |           |         `-{menu-cache-io}
        |         |         |           |-openbox-+-{gdbus}
        |         |         |           |         `-{gmain}
        |         |         |           |-pcmanfm-+-evince-+-{EvJobScheduler}
        |         |         |           |         |        |-{dconf worker}
        |         |         |           |         |        |-{gdbus}
        |         |         |           |         |        `-{gmain}
        |         |         |           |         |-lxterminal-+-bash-+-2*[cat]
        |         |         |           |         |            |      |-ex22.out-+-ex22.out-+-ex22.out-+-ex22.out-+-ex22.out---ex22+
        |         |         |           |         |            |      |          |          |          |          `-ex22.out
        |         |         |           |         |            |      |          |          |          |-ex22.out---ex22.out
        |         |         |           |         |            |      |          |          |          `-ex22.out
        |         |         |           |         |            |      |          |          |-ex22.out-+-ex22.out---ex22.out
        |         |         |           |         |            |      |          |          |          `-ex22.out
        |         |         |           |         |            |      |          |          |-ex22.out---ex22.out
        |         |         |           |         |            |      |          |          `-ex22.out
        |         |         |           |         |            |      |          |-ex22.out-+-ex22.out-+-ex22.out---ex22.out
        |         |         |           |         |            |      |          |          |          `-ex22.out
        |         |         |           |         |            |      |          |          |-ex22.out---ex22.out
        |         |         |           |         |            |      |          |          `-ex22.out
        |         |         |           |         |            |      |          |-ex22.out-+-ex22.out---ex22.out
        |         |         |           |         |            |      |          |          `-ex22.out
        |         |         |           |         |            |      |          |-ex22.out---ex22.out
        |         |         |           |         |            |      |          `-ex22.out
        |         |         |           |         |            |      `-pstree
        |         |         |           |         |            |-gnome-pty-helpe
        |         |         |           |         |            |-{gdbus}
        |         |         |           |         |            `-{gmain}
        |         |         |           |         |-{gdbus}
        |         |         |           |         |-{gmain}
        |         |         |           |         `-2*[{pool}]
        |         |         |           |-ssh-agent
        |         |         |           |-{gdbus}
        |         |         |           `-{gmain}
        |         |         |-{gdbus}
        |         |         `-{gmain}
        |         |-{gdbus}
        |         `-{gmain}
        |-menu-cached-+-{gdbus}
        |             `-{gmain}
        |-nm-applet-+-{dconf worker}
        |           |-{gdbus}
        |           `-{gmain}
        |-ntpd
        |-polkitd-+-{gdbus}
        |         `-{gmain}
        |-pulseaudio-+-{alsa-sink-Intel}
        |            `-{alsa-source-Int}
        |-rsyslogd-+-{in:imklog}
        |          |-{in:imuxsock}
        |          `-{rs:main Q:Reg}
        |-rtkit-daemon---2*[{rtkit-daemon}]
        |-ssh-agent
        |-systemd---(sd-pam)
        |-systemd-journal
        |-systemd-logind
        |-systemd-udevd
        |-udisksd-+-{cleanup}
        |         |-{gdbus}
        |         |-{gmain}
        |         `-{probing-thread}
        |-update-notifier-+-{dconf worker}
        |                 |-{gdbus}
        |                 `-{gmain}
        |-upowerd-+-{gdbus}
        |         `-{gmain}
        |-whoopsie-+-{gdbus}
        |          `-{gmain}
        |-xfce4-power-man-+-{gdbus}
        |                 `-{gmain}
        `-xfconfd




 */
       