import java.util.*;
import java.net.*;
import java.io.*;
public class GobackServer {
	public static void main(String args[]) throws IOException
	{
		ServerSocket ss=new ServerSocket(4001);
		Socket s=ss.accept();
		DataInputStream in=new DataInputStream(s.getInputStream());
		DataOutputStream out=new DataOutputStream(s.getOutputStream());
		Scanner sc=new Scanner(System.in);
		int frame_size=10,m,res,val=0;
		double wind;
		int []a=new int[frame_size];
		for(int i=0;i<frame_size;i++)
		{
			System.out.println("Frame no. is: "+ (i+1));
			a[i]=sc.nextInt();
		}
		System.out.println("Enter the value of m:\n");
		m=sc.nextInt();
		wind=(Math.pow(2,m))-1;
		out.writeInt(m);
		for(int i=0;i<a.length;i++)
		{
			if((i-val)%wind==0 && i>0)
			{
				res=in.readInt();
				if(res!=1)
				{
					int j;
					res=in.readInt();
					System.out.println("lets retransmit it:\n");
					for(j=res-1;j<res-1+wind;j++)
						out.writeInt(a[j]);
					i=j;
					val=(res-1)/(int)wind;
					continue;
				}
				else
				{
					System.out.println("Enter 1 if You've received the acknowledgement for the frame"+ i + ":\n ");
					res=sc.nextInt();
					out.writeInt(res);
					if(res!=1)
					{
						int j;
						for(j=res-1;j<res-1+wind;j++)
							out.writeInt(a[j]);
						i=j;
						continue;
					}
				}
			}
			if(i==a.length)
				break;
			out.writeInt(a[i]);
		}
		in.close();
		out.close();
		sc.close();
		s.close();
		ss.close();
	}
}
