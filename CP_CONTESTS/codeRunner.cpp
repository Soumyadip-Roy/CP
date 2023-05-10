int mxd = x[0] - 1;

                for (int i = 0; i < n - 1; i++)
                {
                    mxd = max(x[i + 1] - x[i] - 1, mxd);
                }

                if (n)
                    mxd = max(s.length() - x[n - 1], mxd);

                cout << mxd << " ";
                int res = mxd / 2 + 1;

                ans = min(ans, res);