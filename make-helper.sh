#!/usr/bin/env bash

help() {
    printf 'build         => make\n'
    printf 'clean         => make clean\n'
    printf 'sanitize      => make sanitize\n'
    printf 'exit, quit, q => quit program\n'
    printf 'clear         => clear screen\n'
    printf 'help          => print this message\n'
}

main() {
    clear

    while true; do
        printf "make> "
        read -r command

        case "$command" in
            build) make ;;
            clean) make clean ;;
            sanitize) make sanitize ;;
            clear) clear ;;
            exit|quit|q) clear
                         break ;;
            help) help ;;
            *) printf 'Unknown command: %s\n' "$command" ;;
        esac
    done
}

main "$@"
