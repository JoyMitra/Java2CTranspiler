package esj.codegen;

import java.io.File;
import java.net.URI;

import sjc.test.Util;

public class Cutil extends Util {

	public static String getResource(final Class<?> c, final String relpath,
		      final String filename) throws Exception {
		    return new File(new URI(c.getResource(relpath).toURI().toASCIIString()
		        .replace("/bin", "/bin/esj/codegen/" + filename))).getAbsolutePath();
		  }
}
