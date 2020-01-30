#
# Regular cron jobs for the natron package
#
0 4	* * *	root	[ -x /usr/bin/natron_maintenance ] && /usr/bin/natron_maintenance
