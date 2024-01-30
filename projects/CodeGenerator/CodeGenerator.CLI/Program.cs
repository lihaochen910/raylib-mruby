using Pixpil.RaylibMRubyBindingsGenerator;

class Program {

	static void Main( string[] args ) {

		if ( args.Length < 2 ) {
			Console.WriteLine( "invalid args." );
			Console.WriteLine( "arg0: RaylibIncludePath" );
			Console.WriteLine( "arg1: Output c file path" );
			return;
		}
		
		var raylibIncludePath = args[ 0 ];
		var outputPath = args[ 1 ];

		Console.WriteLine( $"start parsing: {raylibIncludePath}" );

		string parsed = Generator.Parse( raylibIncludePath );
		File.WriteAllText( outputPath, parsed );

		Console.WriteLine( "finished." );

	}
}
