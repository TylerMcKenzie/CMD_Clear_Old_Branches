package src;

import sys.io.Process;
import haxe.io.Input;

class Main {
    private static var input:Input = Sys.stdin();

    public static function main() : Void
    {
        var branches:Array<String> = getBranches();

        var currentBranchRegexp:EReg = ~/\*/;

        for (branch in branches) {
            var branch:String = StringTools.trim(branch);

            if (
                branch == "master" ||
                branch == "" ||
                currentBranchRegexp.match(branch)
            ) {
                continue;
            }

            var lastBranchCommit:String = new Process("git", ["log", "--pretty=format:\"%ad\"", "-1", branch]).stdout.readAll().toString();

            Sys.print("\n[BRANCH]: " + branch + "\n");
            Sys.print("[LAST_UPDATE]: " + lastBranchCommit + "\n");
            Sys.print("Delete this branch? [Y/N]: ");
            var userInput:String = input.readLine();

            if (userInput == "y" || userInput == "Y") {
                deleteBranch(branch);
            }
        }
    }

    private static function getBranches() : Array<String>
    {
        return new Process("git", ["branch"]).stdout.readAll().toString().split("\n");
    }

    private static function deleteBranch(branch:String) : Void
    {
        Sys.command("git", ["branch", "-d", branch]);
    }
}
