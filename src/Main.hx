package src;

import sys.io.Process;

class Main {
    private static var input = Sys.stdin();

    public static function main()
    {
        var branches:Array<String> = new Process("git", ["branch"]).stdout
                                                                   .readAll()
                                                                   .toString()
                                                                   .split("\n");

        var currentBranchRegexp:EReg = ~/\*/;

        for (branch in branches) {
            var branch = StringTools.trim(branch);
            if (
				branch == "master" ||
				branch == "" ||
				currentBranchRegexp.match(branch)
			) {
                continue;
            }

            var lastBranchCommit = new Process("git", ["log", "--pretty=format:\"%ad\"", "-1", branch]).stdout.readAll().toString();

            Sys.print("[BRANCH]: " + branch + "\n");
            Sys.print("[LAST_UPDATE]: " + lastBranchCommit + "\n");
            Sys.print("Delete this branch? [Y/N]: ");
            var userInput = input.readLine();

            if (userInput == "y" || userInput == "Y") {
                Sys.print("Deleting branch (" + branch + ")...\n");
                deleteBranch(branch);
            }
        }
    }

    private static function getBranches(): Array<String>
    {
        return new Process("git", ["branch"]).stdout.readAll().toString().split("\n");
    }

    private static function deleteBranch(branch:String)
    {
        Sys.command("git", ["branch", "-d", branch]);
    }
}
