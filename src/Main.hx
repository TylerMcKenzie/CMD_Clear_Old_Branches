package src;

import sys.io.Process;

class Main {
    public static function main()
    {
        var dirtyBranches:Array<String> = new Process("git", ["branch"]).stdout
                                                                   .readAll()
                                                                   .toString()
                                                                   .split("\n");

        var currentBranchRegexp:EReg = ~/\*/;
        var cleanBranches:Array<Dynamic> = [];

        for (branch in dirtyBranches) {
            if (
				branch == "master" || 
				branch == "" || 
				currentBranchRegexp.match(branch) 
			) {
                continue;
            }

            cleanBranches.push({ branch: branch });
        }


		for (cleanBranch in cleanBranches) {
			var lastBranchCommit = new Process("git", ["log", "-pretty:format\"%ad\"", "-1", cleanBranch.branch]).stdout.readAll().toString();
			trace(cleanBranch.branch + ": " + lastBranchCommit");
		}

        trace(dirtyBranches);
    }
}
