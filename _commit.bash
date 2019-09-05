 #!/bin/bash

# -----------------------------------------------------------
# Konfigurierbar
# -----------------------------------------------------------
execute_in_konsole() {
	echo "Commit Message:"
	read message
	echo
	git add -A
	git commit -m "$message"
	echo
	read -rsp "" -n 1 pause1
}


# -----------------------------------------------------------
# Fix
# -----------------------------------------------------------
open_konsole() {
	local -r start_script="bash \"$BASH_SOURCE\" \"$in_konsole_switch\""

	# --noclose für debugging
	exec konsole -e "$start_script"
}


run() {
	readonly in_konsole_switch="Ggzk49Y5fqc3rh2gZkoWxKc2i"

	if [[ "$#" -eq 0 ]]; then # Gar nichts übergeben: Konsole öffnen und diese Datei ausführen
		open_konsole
	elif [[ "$1" == "$in_konsole_switch" ]]; then # "$in_konsole_switch" übergeben: execute_in_konsole() wird ausgeführt
		execute_in_konsole
	else
		open_konsole # Etwas anderes übergeben
	fi
}


init_bash() {
	# https://vaneyckt.io/posts/safer_bash_scripts_with_set_euxo_pipefail/
	# Exit on failure, pipe failure
	# -x hinzufügen hilft zum Debuggen noch mehr
	set -Eeuo pipefail
	trap exit_hook INT TERM
}


exit_hook() {
	jobs -p | xargs kill
}


main() {
	init_bash
	run "$@"
}


# main() Funktion ausführen
main "$@"


# -----------------------------------------------------------

