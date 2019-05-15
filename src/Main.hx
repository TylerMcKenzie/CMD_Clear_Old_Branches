package src;

import sys.io.Process;

class Main {
    private static var input = Sys.stdin();

    public static function main()
    {
        var dirtyBranches:Array<String> = new Process("git", ["branch"]).stdout
                                                                   .readAll()
                                                                   .toString()
                                                                   .split("\n");

        var currentBranchRegexp:EReg = ~/\*/;
        var cleanBranches:Array<Dynamic> = [];

        for (dirtyBranch in dirtyBranches) {
            var branch = StringTools.trim(dirtyBranch);
            if (
				dirtyBranch == "master" ||
				dirtyBranch == "" ||
				currentBranchRegexp.match(dirtyBranch)
			) {
                continue;
            }

            cleanBranches.push({ branch: branch });
        }


		for (cleanBranch in cleanBranches) {
			var lastBranchCommit = new Process("git", ["log", "--pretty=format:\"%ad\"", "-1", cleanBranch.branch]).stdout.readAll().toString();

			Sys.print("[BRANCH]: " + cleanBranch.branch + "\n");
			Sys.print("[LAST_UPDATE]: " + lastBranchCommit + "\n");
			Sys.print("Delete this branch? [Y/N]: ");
			var userInput = input.readLine();
		}
    }
}
